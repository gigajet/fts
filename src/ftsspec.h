cout<<"fts [-abcv] EXE IP OP [CMP]\n";
cout<<"Test EXE with input pattern IP against input pattern OP with compare CMP.\n";
cout<<"Iterate counter from 0, substitute counter to any instance of '$' in IP and OP,\n";
cout<<"do the test and report the result.\n";
cout<<"\n";
cout<<"EXE is an executable which read from STDIN and output to STDOUT.\n";
cout<<"\n";
cout<<"IP and OP minilanguage\n";
cout<<"	+ $ is placeholder for counter, which is iterated from 0\n";
cout<<"	For example, for the pattern 'i$.txt' the files are iterated as:\n";
cout<<"		i0.txt, i1.txt, i2.txt, ...\n";
cout<<"	+ All not mentioned tokens are treated as literals.\n";
cout<<"\n";
cout<<"Compare CMP expected behavior\n";
cout<<"	+ Is an EXEcutable.\n";
cout<<"	+ Take 2 arguments as 2 file name to compare.\n";
cout<<"	+ Has Cantrip interface pattern.\n";
cout<<"		+ Expected to write nothing to stdout\n";
cout<<"		+ Zero exit code for a positive ('identical').\n";
cout<<"		+ Non-zero exit code for a negative ('different')\n";
cout<<"\n";
cout<<"Default CMP: string token-by-token comparison.\n";
cout<<"	Blank lines are discarded.\n";
cout<<"	Do not distinguish between spaces and tabs.\n";
cout<<"	Multiple spaces are seen as one space.\n";
cout<<"	Respective tokens are compared.\n";
cout<<"	\n";
cout<<"An invocation example\n";
cout<<"	You run fts as 'fts E i$.txt o$.txt' using default compare.\n";
cout<<"	E is executed with input from i0.txt. E's output is compared with o0.txt.\n";
cout<<"	In the next phase, input would be i1.txt. Output is compared with o1.txt\n";
cout<<"	Next phase is with i2.txt and o2.txt and so on...\n";
cout<<"	until a number K where either iK.txt or oK.txt is not found.\n";
cout<<"	Execution is then stopped.\n";
cout<<"\n";
cout<<"Testing behavior option (latter override former switch):\n";
cout<<"-a	ACM mode [default]. Stop right away on a wrong test case.\n";
cout<<"-b	Batch score mode. Run all test until a missing file encountered.\n";
cout<<"Output option (latter override former switch):\n";
cout<<"-c	Concise mode [default]. Only wrong test cases are displayed.\n";
cout<<"-v	Verbose mode. Display all test cases tested.\n";