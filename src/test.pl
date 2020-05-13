#!perl
use diagnostics;

sub usage {
print "test exec inp out cmp\n";
print "Run exec < inp and compare output with out using cmp.\n";
print "exec and cmp are executable files, inp and out are text files.\n";
print "Emit no output if called with at least 3 arguments.\n";
print "Exit code 0 if cmp return 0.\n";
print "Exit code 1 if cmp return non-zero.\n";
print "Exit code 2 with any other errors.\n";
exit 13;
}

my $argc = @ARGV;
usage() if ($argc < 4);
(-e $ARGV[0] and -e $ARGV[1] and -e $ARGV[2] and -e $ARGV[3]) || exit 2;
my ($exec,$in,$out,$cmp)=@ARGV;
my $tmp = '$~test~$.tmp';
system("$exec < $in > $tmp");
my $ans=system("$cmp $out $tmp");
exit ($ans==0?0:1);
