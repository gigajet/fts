//Substitution engine
#ifndef __sub_h__
#define __sub_h__

#include <string>
#include <sstream>
using namespace std;

string subst(string pattern, int counter) {
	ostringstream oss;
	for (char ch: pattern) {
		if (ch=='$')
			oss<<counter;
		else if (ch=='"') ;
		else oss<<ch;
	}
	return oss.str();
}

bool substitable(string pattern) {
	bool dollar_sign = false;
	for (char ch : pattern)
		if (ch=='$') dollar_sign=true;
	return dollar_sign;
}

#endif