/* 
 * sort_v1.cpp
 *
 * Author: Steven Peters			
 * Date: August 14, 2019
 * 	
 * This program takes as input a file containing numbers and arranges
 * them in either ascending or descending order, as well as removes duplicates
 * according to the user's input commands
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

void print_usage(char prgm_nm[]);

void remove_duplicates(vector<double> &vect);

void read_from_file(vector<double> &vect, string &f_name);

void write_to_file(vector<double> &vect, string &f_name);

const string DEFAULT_FILENAME = "sorted.dat"; // Default output name

int main(int argc, char *argv[]) {

	extern char *optarg;
	extern int optind;
	int c, err = 0;

	// aflag is ascending; dflag is descending; iflag is input 
	int aflag = 0, dflag = 0, iflag = 0;
	string input_name, output_name = DEFAULT_FILENAME;

	vector<double> v; // This vector contains all numbers from the input file

	while((c = getopt(argc, argv, "adi:h")) != -1) {
		switch(c) {
			case 'a':
				aflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			case 'i':
				iflag = 1;
				input_name = optarg;
				break;
			case 'h':
				print_usage(argv[0]);
				exit(1);
			case '?':
				err = 1;
				break;
		}
	}

	if(iflag == 0) {	/* -i is manditory */
		cerr << argv[0] << ": missing -i option\n" << endl;
		print_usage(argv[0]);
		exit(1);
	} else if((optind) > argc) {
		/* need at least one argument for input file */
		
		cerr << argv[0] << ": missing input filename" << endl;
		print_usage(argv[0]);
		exit(1);
	} else if(err) {
		print_usage(argv[0]);
		exit(1);
	}

	
	// Read elements from file
	read_from_file(v, input_name);

	// Sort
	if(aflag)
		sort(v.begin(), v.end());
	if(dflag)
		sort(v.begin(), v.end(), greater<double>());

	if (optind < argc)	/* Takes output file take from command line if present */
			output_name = argv[optind];

	// Write sorted array to file
	write_to_file(v, output_name);

	return 0;
}

void print_usage(char prgm_nm[]) {
	cerr << "usage: " << prgm_nm << " [-ad] -i input [output]\n\n";
	cerr << "\t-h \tdisplay this message\n";
	cerr << "\t-a \tascending order\n";
	cerr << "\t-d \tdescending order\n";
	cerr << "\toutput \t[default = " << DEFAULT_FILENAME << "]\n";
	//cerr << "-i precedes the input filename\n";
	}

void remove_duplicates(vector<double> &vect) {

	vector<double>::iterator itr = vect.begin();
	unordered_set<double> s;

	for (auto curr = vect.begin(); curr != vect.end(); ++curr) {
		if (s.insert(*curr).second)
			*itr++ = *curr;
	}

	vect.erase(itr, vect.end());
}

void read_from_file(vector<double> &vect, string &f_name) {

	double temp;
	ifstream in;
	in.open(f_name.c_str());

	if( in.is_open() ) {

		while ( !in.eof() ) {
			in >> temp;
			vect.push_back(temp);
		}
	}
	else
		cout << "Error. File could not be opened" << endl;

	in.close();
}

void write_to_file(vector<double> &vect, string &f_name) {

	ofstream out;

	// Write sorted elements to file
	out.open(f_name.c_str());

	if( out.is_open() ) {

		for(int i = 0; i < vect.size(); i++) {
			out << vect[i] << " ";

			// File will contain 30 numbers in each row
			if( ( (i+1) % 30 ) == 0 )
				out << endl;
		}
	}
	else
		cout << "Error. File could not be opened." << endl;

	// Close output stream
	out.close();

	cout << "Sorted numbers written to " << f_name << endl;
}

