#!perl
while (<>) {
	chomp;
	s/^/print "/;
	s/$/\\n";/;
	print "$_\n";
}