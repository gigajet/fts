#include "sub.h"
#include "fexist.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string exe, ip, op, cmp;
bool ACM, verbose, verboseHelp;
vector<string> args; //Non-switch arguments
string switches;

void fatal (int exitcode, const char *message) {
	cerr<<message<<"\n";
	cout<<"Testing terminated\n";
	exit(exitcode);
}

void parseArgument(int argc, char **argv) {
	for (int i=1; i<argc; ++i) {
		string token = argv[i];
		if (token[0]=='-') {
			for (char ch : token) {
				if (ch!='-') switches+=ch;
			}
		}
		else {
			args.push_back(token);
		}
	}	
}


void selfConfig (const vector<string> args, string switches) {
	ACM=true; verbose=false; verboseHelp=false;
	for (char c : switches)
		switch (c) {
			case 'a': ACM=true; break;
			case 'b': ACM=false; break;
			case 'c': verbose=false; break;
			case 'v': verbose=true; break;
			case 'h': verboseHelp=true; break;
		}
}

void prepare () {
	/* Assignments
	*/
	if (args.size()<1)
		fatal(13, "fts: fatal error: No EXE file");
	else exe=args[0];
	
	if (args.size()>=2) ip=args[1];
	else fatal(13, "fts: fatal error: No Input Pattern");
	
	if (args.size()>=3) op=args[2];
	else fatal(13, "fts: fatal error: No Output Pattern");
	
	if (args.size()>=4) cmp=args[3];
	else cmp="cmp.exe";
	/* Test for existence of EXE and CMP
	*/
	if (nf(exe)) fatal(13, "fts: fatal error: EXEcutable not found");
	if (nf(cmp)) fatal(13, "fts: fatal error: CoMPare not found\n"
	"Did you copy default cmp.exe in the same directory?");
	if (nf("ftest.exe")) fatal(13, "fts: fatal error: ftest.exe not found"
	"\nDid you copy test.exe in the same directory?");
}

int ftest (string exe, string i, string o, string cmp) {
	string cmd = "ftest.exe "+exe+" "+i+" "+o+" "+cmp;
	//cerr<<cmd<<"\n";
	int ret=system(cmd.c_str());
	return ret;
}

void displayUsage() {
#include "ftsusage.h"
exit(13);
}

void displayVerboseUsage() {
#include "ftsspec.h"
exit(13);
}

int main(int argc, char **argv) {
	if (argc==1)
		displayUsage();
	parseArgument(argc, argv);
	//cerr<<switches<<" args: "; for (auto x:args) cerr<<x<<" "; cerr<<"\n";
	selfConfig(args, switches);
	if (verboseHelp)
		displayVerboseUsage();
	prepare();
	int counter = 0, AC=0, WA=0;
	if (substitable(ip) || substitable(op)) {
		string i = subst(ip, counter);
		string o = subst(op, counter);
		//cerr<<i<<" "<<o<<"\n";
		while (!nf(i) && !nf(o)) {
			int testRes = ftest(exe,i,o,cmp);
			if (testRes == 0) {
				if (verbose)
					cout<<exe<<" "<<i<<" "<<o<<" "<<"AC\n";
				++AC;
			}
			if (testRes != 0) {
				cout<<exe<<" "<<i<<" "<<o<<" "<<"WA\n";
				++WA;
				if (ACM) break;
			}
			++counter;
			i = subst(ip, counter);
			o = subst(op, counter);
		}
	}
	else { //No "$" in pattern. One time test
		if (!nf(ip) && !nf(op)) {
			int testRes = ftest(exe,ip,op,cmp);
			if (testRes == 0)
				++AC;
			else 
				++WA;
		}
	}
	cout<<"Total: AC "<<AC<<" / "<<AC+WA<<" test cases\n";
	return 0;
}
