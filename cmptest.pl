#!perl
my $x = system('bin/cmp','cmpt/a0','cmpt/b0') >> 8;
print "C0 $x\n"; #0
$x = system('bin/cmp','cmpt/a1','cmpt/b1') >> 8;
print "C1 $x\n"; #!0
$x = system('bin/cmp','cmpt/a2','cmpt/b2') >> 8;
print "C2 $x\n"; #0
$x = system('bin/cmp','cmpt/a3','cmpt/b3') >> 8;
print "C3 $x\n"; #0
