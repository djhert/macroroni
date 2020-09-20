#include "mStorage.hpp"

makStore::~makStore() {}

bool makStore::Set(const wxString &name) {
	if (wxFileExists(name)) {
#ifdef _DEBUG
		std::cout << "File Exists: " << name << std::endl;
#endif
		_name = name;
	} else {
#ifdef _DEBUG
		std::cout << "File does not exist: " << name << std::endl;
#endif
		return false;
	}
	return true;
}

bool makStore::Open() {
	if (!_file.Open(_name))
		return false;
	// Parse the file
	return load();
}

bool makStore::load() {
	std::string line = "";
	std::string _ml_text = "";
	std::string _ml_key = "";

	int linecount = 0;
	int refcount = 0;
	int previter = 0;
	int multistarted = 0;
	while (!_file.Eof()) {
		line = _file.GetNextLine().ToStdString();
		linecount++;
		if (previter < 2)
			previter = parseLine(line, _name, linecount, _ml_key);
		else
			previter = parseMultiLine(line, _name, linecount, _ml_key, _ml_text);
		if (previter == 0) {
			_ml_text = "";
			_ml_key = "";
			multistarted = 0;
		} else if (previter == 1) {
			refcount++;
			_ml_text = "";
			_ml_key = "";
			multistarted = 0;
		} else if (previter == 2) {
			if (multistarted == 0) multistarted = linecount;
			refcount++;
		}
	}
	if (multistarted != 0) {
		std::cerr << "Error: " << _name << " | Line: " << multistarted
				  << " | Key: " << _ml_key << " | Multiline started but never ends"
				  << std::endl;
		return false;
	}
#ifdef _DEBUG
	std::cout << "Done reading '" << _name << "'\nLines Read: " << linecount
			  << "\nLines Parsed: " << refcount << std::endl;
#endif
	return true;
}

int makStore::parseLine(const std::string &line, const wxString &name,
		const int &linenum, std::string &ret_key) {

	if (line.front() == '#') return 0;
	if (line.front() == '\n') return 0;
	if (line.empty()) return 0;

	size_t _first = line.find(":");
	if (_first == std::string::npos || _first > 0) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Unable to parse line\n  \"" << line << "\"" << std::endl;
		return 0;
	}
	size_t _kw_type = line.find(":", _first + 1);
	size_t _kw_key = line.find(":", _kw_type + 1);
	size_t _kw_var = line.find(":", _kw_key + 1);
	if (_kw_type == std::string::npos) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Missing type and key\n  \"" << line << "\"" << std::endl;
		return 0;
	}
	if (_kw_key == std::string::npos) {
		if (_kw_type > 2) {
			std::cerr << "Error: " << name << " | Line: " << linenum
					  << " | Missing type\n  \"" << line << "\"" << std::endl;
		} else {
			std::cerr << "Error: " << name << " | Line: " << linenum
					  << " | Missing key\n  \"" << line << "\"" << std::endl;
		}
		return 0;
	}
	if (_kw_var == std::string::npos) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Missing var\n  \"" << line << "\"" << std::endl;
		return 0;
	}

	int _itype = 0;
	std::string _type = line.substr(1, _kw_type - 1);
	std::string key = line.substr(_kw_type + 1, _kw_key - (_kw_type + 1));
	std::string var = line.substr(_kw_key + 1, _kw_var - (_kw_key + 1));
	std::string rest = line.substr(_kw_var + 1);
	if (rest.empty()) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Missing value\n  \"" << line << "\"" << std::endl;
		return 0;
	}
	if (_kw_type == 1) {
		_itype = 1;
	} else if (_type == "r")
		_itype = 1;
	else if (_type == "d")
		_itype = 2;
	else if (_type == "c")
		_itype = 3;
	else if (_type == "s")
		_itype = 4;

	if (_itype == 0) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Unkown type " << _type << "\n  \"" << line << "\""
				  << std::endl;
		return 0;
	}

	ret_key = key;
	if (rest == "{") {
		return 2;
	}
#ifdef _DEBUG
	std::cout << name << ": Adding line " << linenum << " as type " << _itype
			  << " | Key: " << key << " | Text: " << rest << std::endl;
#endif
	int retadd = addAction(key, rest);
	if (retadd == 1) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Unable to get key\n  \"" << line << "\"" << std::endl;
		return 0;
	} else if (retadd == 2) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Unable to get value\n  \"" << line << "\"" << std::endl;
		return 0;
	} else if (retadd == 3) {
		std::cerr << "Error: " << name << " | Line: " << linenum
				  << " | Duplicate Key: \"" << key << "\"" << std::endl;
		return 0;
	}
	return 1;
}

int makStore::parseMultiLine(const std::string &line, const wxString &name,
		const int &linenum, std::string &ret_key,
		std::string &ret_text) {
	if (line == "}") {
#ifdef _DEBUG
		std::cout << name << ": Adding line " << linenum << " as type 1"
				  << " | Key: " << ret_key << " | Text: " << ret_text << std::endl;
#endif
		int retadd = addAction(ret_key, ret_text);
		if (retadd == 1) {
			std::cerr << "Error: " << name << " | Line: " << linenum
					  << " | Unable to get key\n  \"" << line << "\"" << std::endl;
			return 0;
		} else if (retadd == 2) {
			std::cerr << "Error: " << name << " | Line: " << linenum
					  << " | Unable to get value\n  \"" << line << "\"" << std::endl;
			return 0;
		} else if (retadd == 3) {
			std::cerr << "Error: " << name << " | Line: " << linenum
					  << " | Duplicate Key: \"" << ret_key << "\"" << std::endl;
			return 0;
		}
		return 1;
	} else {
		if (ret_text == "")
			ret_text = line;
		else
			ret_text += "\n" + line;
		return 2;
	}
	return 0;
}

// 0 = success
// 1 = no key
// 2 = no value
// 3 = duplicate key
int makStore::addAction(const std::string &k, const std::string &v) {
	if (k.empty()) return 1;
	if (v.empty()) return 2;

	wxString key(k);
	wxString value(v);
	wxString temp = "";
	actions.Get(key, temp);
	if (temp != "") return 3;

	actions.Push(key, value);
	return 0;
}