#ifndef _mSTORAGE_HPP_
#define _mSTORAGE_HPP_

#include "threadmap.hpp"

#include <wx/textfile.h>
#include <wx/wx.h>

class makStore {
public:
	makStore() = default;
	~makStore();

	// Checks if the file exists, and stores the name
	bool Set(const wxString &name);

	bool Open();

	threadmap<wxString, wxString> actions;

	bool Empty;

private:
	wxString _name;
	wxTextFile _file;

	bool load();
	int parseLine(const std::string &_line, const wxString &name, const int &linenum,
			std::string &ret_key);
	int parseMultiLine(const std::string &line, const wxString &name, const int &linenum,
			std::string &ret_key, std::string &ret_text);
	int addAction(const std::string &key, const std::string &value);
};

#endif