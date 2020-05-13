#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
void displayUsage() {
#include "testusage.h"
}
bool nf (char *file) {
	ifstream fin(file);
	if (!fin.is_open()) return true;
	fin.close(); return false;
}
void test(string exe, string inp, string out, string cmp) {
	//Temporary file is $~test~$.tmp
	string tmp="$~test~$.tmp";
	string cmd=exe+" < "+inp+" > "+tmp;
	system(cmd.c_str());
	cmd = cmp+" "+out+" "+tmp;
	int cmpRes=system(cmd.c_str());
	remove(tmp.c_str());
	exit((cmpRes==0?0:1));
}
int main(int argc, char **argv) {
	if (argc < 5) {
		displayUsage();
		exit(13);
	}
	if (nf(argv[1])||nf(argv[2])||nf(argv[3])||nf(argv[4]))
		exit(2);
	
	test(argv[1], argv[2], argv[3], argv[4]);
	exit(13);
}