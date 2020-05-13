# fts
Automatic tester with simple pattern

## An invocation example
```
fts E.exe i$.txt o$.txt
```
E.exe is executed with input from i0.txt. E's output is compared with o0.txt.

In the next phase, input would be i1.txt. Output is compared with o1.txt

Next phase is with i2.txt and o2.txt and so on...
until a number K where either iK.txt or oK.txt is not found.

Execution is then stopped. Compare results are printed to stdout.

## Release
Requirement: Windows (only tested on windows 7)

Download built binaries [here](https://github.com/gigajet/fts/releases)

## Build from source
### Prerequisites
```
gcc
Perl 5 (Don't need if you're not changing src/*.txt)
make (prefer gmake)
```
### Make any changes you prefer (in src/*)
These *.h files in src/ are not important. Ignore them for now. Ignore irrelevances.

*.txt is to store usage help (those help when running with no argument).

txt files are converted to `cout` codes later.

This program has 3 subprogram:
+ cmp : the default compare, responsible for comparing 2 files

		cmpusage.txt
	
		cmp.cpp
	
+ ftest : the single file tester

		test.cpp
	
		testusage.txt
	
+ fts : substitution engine and iteration. Main program. Main interface.

		ftsusage.txt
	
		ftsspec.txt : verbose usage
	
	fts.cpp : counter iteration
	
	sub.h : substitution $ for number

### Compile
Compile everything.
```
make prepare
make all
```

If you compile everything, you don't need to do the following.

Compile just the code, but keep the usage help intact.

This compilation doesn't convert usage txts into cout code.

In this compilation, Perl 5 is not required.
```
make prepare
make main
```

