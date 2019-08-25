// Author: Steven Peters
// Date: August 2, 2019
// This program writes random numbers to a file

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <getopt.h>
#include <stdlib.h>	/* atoi, exit */

using namespace std;

const string DEFAULT_OUTFILE = "numbers.dat";

void print_usage(string pgrm_nm) {
	cerr << "usage: " << pgrm_nm << " [-s <n>] [<outfile>]\n\n";
	cerr << "\t-h, --help\tPrint this help message and exit\n";
	cerr << "\t-s, --size <n>\tAmount of random numbers to produce [default: 3000]\n";
	cerr << "\t    <outfile>\toutput file [default: " << DEFAULT_OUTFILE << "]\n";
}

void writeToFile(string &f_name, unsigned int size) {

	ofstream output;
	output.open(f_name.c_str());

	if( output.is_open() ) {
		for(unsigned int i = 1; i <= size; i++) {
			output << rand()%1000 << " ";
			
			if( (i%30) == 0 ) /* File will contain 30 numbers in each row */
				output << endl;
		}

		cout << "Random numbers written to " << f_name << endl;
	}
	else {
		cout << "Error. File could not be opened." << endl;
		exit(1);
	}

	output.close();
}

int main(int argc, char* argv[]) {

	srand(time(0)); // Use current time as seed for random generator 

	string program_name = argv[0];
	string filename = DEFAULT_OUTFILE;
	unsigned int size = 3000; // Default amount of numbers to write to file
	int c, err = 0;

	while (1)
	{
		int option_index = 0;
		static struct option long_options[] = {
			{"help", no_argument, 0, 'h'},
			{"size", required_argument, 0, 's'},
			{0, 0, 0, 0},
		};

		c = getopt_long(argc, argv, "hs:", long_options, &option_index);

		/* Detect the end of the options */
		if (c == -1)
			break;

		switch(c) {
			case 'h':
				print_usage(program_name);
				exit(1);
			case 's':
				size = atoi(optarg);
				break;
			case '?':
				cerr << "Unknown option character " << optopt << endl;
				exit(1);
			default:
				abort();
		}
	}

	if (optind < argc) /* Takes output filename from command line if present */
		filename = argv[optind];

	writeToFile(filename, size);

	return 0;
}

