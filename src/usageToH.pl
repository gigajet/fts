#!perl
while (<>) {
	chomp;
	s/^/cout<<"/;
	s/$/\\n";/;
	print "$_\n";
}