#ifndef _THREADMAP_HPP_
#define _THREADMAP_HPP_

#include <wx/wx.h>

#include <mutex>
#include <unordered_map>

template <typename T, typename D>
class threadmap {
public:
	threadmap() {}
	~threadmap() { data.clear(); }
	threadmap &operator=(threadmap &) = delete;

	void Push(T key, D value) {
		std::lock_guard<std::mutex> lk(mut);
		data[key] = value;
	}

	void Get(T key, D &value) {
		std::unique_lock<std::mutex> lk(mut);
		if (data.find(key) != data.end()) {
			value = data[key];
		}
		lk.unlock();
	}

	int Count() {
		std::unique_lock<std::mutex> lk(mut);
		int c = data.size();
		lk.unlock();
		return c;
	}

	wxArrayString GetActions() {
		wxArrayString str = wxArrayString();
		for (auto it = data.begin(); it != data.end(); ++it)
			str.Add(it->first);
		return str;
	}

#ifdef _DEBUG
	void Print() {
		std::cout << "\nPrinting available keys and values" << std::endl;
		std::unique_lock<std::mutex> lk(mut);
		for (auto it = data.begin(); it != data.end(); ++it)
			std::cout << "Key: " << it->first << " | Text: " << it->second
					  << std::endl;
		lk.unlock();
	}
#endif
private:
	std::mutex mut;
	std::unordered_map<T, D> data;
};

#endif