
all: cmp test fts
main: cmpmain testmain ftsmain
cmp: cmpusage cmpmain
test: testusage testmain
fts: ftsusage ftsspec ftsmain

ftsmain:
	g++ -o bin/fts.exe src/fts.cpp

ftsspec:
	perl src/usageToH.pl < src/ftsspec.txt > src/ftsspec.h

ftsusage:
	perl src/usageToH.pl < src/ftsusage.txt > src/ftsusage.h

testusage:
	perl src/usageToH.pl < src/testusage.txt > src/testusage.h
	
testmain:
	g++ -o bin/ftest.exe src/test.cpp

cmpusage:
	perl src/usageToH.pl < src/cmpusage.txt > src/cmpusage.h
	
cmpmain:
	g++ -o bin/cmp.exe src/cmp.cpp

prepare:
	mkdir bin

clean:
	del /F bin/*.exe