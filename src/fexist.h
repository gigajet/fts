#ifndef __fexist_h_
#define __fexist_h_

#include <string>
#include <fstream>

bool nf (const char *file) {
	/*
		return True if file is not found.
	*/
	ifstream fin(file);
	if (!fin.is_open()) return true;
	fin.close(); return false;
}
bool nf (std::string file) {
	return nf(file.c_str());
}

#endif