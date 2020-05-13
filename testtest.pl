#!perl

my $x = system('bin\\test','testt.exe','cmpt\\a0','cmpt\\b0','bin\\cmp.exe') >> 8;
print "C0 $x\n"; #0
my $x = system('bin\\test','testt.exe','cmpt\\a1','cmpt\\b1','bin\\cmp.exe') >> 8;
print "C1 $x\n"; #1
my $x = system('bin\\test','testt.exe','cmpt\\a2','cmpt\\b2','bin\\cmp.exe') >> 8;
print "C2 $x\n"; #0
my $x = system('bin\\test','testt.exe','cmpt\\a3','cmpt\\b3','bin\\cmp.exe') >> 8;
print "C3 $x\n"; #0
