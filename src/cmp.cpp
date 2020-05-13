#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

ifstream f1, f2;

void nextToken (string *&s1, string *&s2) {
	if (s1 != NULL)
		f1 >> skipws >> *s1;
	if (s2 != NULL)
		f2 >> skipws >> *s2;
	if (f1.fail()) {
		s1 = NULL;
	}
	if (f2.fail()) {
		s2 = NULL;
	}
}

void cmp (char *i1, char *i2) {
	f1.open(i1); f2.open(i2);
	if (!f1.is_open()) exit(2);
	if (!f2.is_open()) exit(2);
	string s1, s2;
	string *p1=&s1, *p2=&s2;
	do {
		nextToken(p1, p2);
		if (p1==NULL && p2==NULL) exit(0);
		if (p1==NULL && p2!=NULL) exit(1);
		if (p1!=NULL && p2==NULL) exit(1);
		if (s1 != s2) {
			exit(1);
		}
	} while (true);
}

void displayUsage() {
#include "cmpusage.h"
exit(13);
}

int main(int argc, char **argv) {
	if (argc < 3) {
		displayUsage();
		return 1;
	}
	cmp(argv[1], argv[2]);
	exit(0);
}