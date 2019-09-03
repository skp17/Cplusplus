/* sort_v1.cpp
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
#include <stdlib.h> 	/* for exit */
#include <getopt.h>
#include <iomanip> 		/* setprecision */
#include <unordered_set>
#include <algorithm> 	/* for sort */

using namespace std;

void print_usage();

void remove_duplicates(vector<double> &vect);

void readFromFile(vector<double> &vect, string &f_name);

void readToFile(vector<double> &vect, string &f_name);

const string DEFAULT_FILENAME = "sorted.dat"; // Default output name
string program_name;

int main(int argc, char *argv[])
{

	const float PRGM_VER = 3.0; // Program version
	program_name = argv[0];
	string input_name, output_name = DEFAULT_FILENAME;
	vector<double> v; /* This vector contains all numbers from the input file */

	// aflag is ascending; dflag is descending; rflag is remove duplicates
	// iflag is input
	int aflag = 0, dflag = 0, rflag = 0, iflag = 0;
	int c, err = 0;

	while (1)
	{
		int option_index = 0;
		static struct option long_options[] = {
			{"ascending", no_argument, &aflag, 1},
			{"descending", no_argument, &dflag, 1},
			{"rm_duplicates", no_argument, &rflag, 1},
			{"input", required_argument, &iflag, 1},
			{"help", no_argument, 0, 'h'},
			{"version", no_argument, 0, 'v'},
			{0, 0, 0, 0},
		};

		c = getopt_long(argc, argv, "adri:hv", long_options, &option_index);

		/* Detect the end of the options */
		if (c == -1)
			break;

		cout << setprecision(1) << fixed;

		switch (c)
		{
		case 'a':
			aflag = 1;
			break;
		case 'd':
			dflag = 1;
			break;
		case 'r':
			rflag = 1;
			break;
		case 'i':
			iflag = 1;
			input_name = optarg;
			break;
		case 'h':
			print_usage();
			exit(1);
		case 'v':
			cout << program_name << " " << PRGM_VER << endl;
			exit(1);
		case '?':
			if (optopt == 'i')
				iflag = 1;
			err = 1;
			break;
		default:
			abort();
		}
	}

	// Handle errors
	if (aflag == 1 && dflag == 1)
	{
		cerr << "Choose either -a or -d. Not both\n";
		exit(1);
	}
	if (iflag == 0)
	{ /* -i is manditory */
		cerr << argv[0] << ": missing -i option\n"
			 << endl;
		print_usage();
		exit(1);
	}
	else if (err)
	{
		print_usage();
		exit(1);
	}

	// Read elements from file
	readFromFile(v, input_name);

	// Sort
	if (aflag)
		sort(v.begin(), v.end());
	if (dflag)
		sort(v.begin(), v.end(), greater<double>());
	if (rflag)
		remove_duplicates(v);

	if (optind < argc) /* Takes output filename from command line if present */
		output_name = argv[optind];

	// Write sorted array to file
	readToFile(v, output_name);

	return 0;
}

void print_usage()
{
	cerr << "usage: " << program_name << " [-a|d] [r] -i <infile> [<outfile>]\n\n";
	cerr << "\t-a, --ascending \t\tascending order\n";
	cerr << "\t-d, --descending \t\tdescending order\n";
	cerr << "\t-r, --remove_duplicates \tremove duplicates\n";
	cerr << "\t-i, --input <infile>\t\tinput file\n";
	cerr << "\t    <outfile> \t\t\toutput file [default: " << DEFAULT_FILENAME << "]\n";
	cerr << "\t-h, --help \t\t\tdisplay this message\n";
	cerr << "\t-v, --version \t\t\tdisplay program version\n";
}

void remove_duplicates(vector<double> &vect)
{

	vector<double>::iterator itr = vect.begin();
	unordered_set<double> s;

	for (auto curr = vect.begin(); curr != vect.end(); ++curr)
	{
		if (s.insert(*curr).second)
			*itr++ = *curr;
	}

	vect.erase(itr, vect.end());
}

void readFromFile(vector<double> &vect, string &f_name)
{

	double temp;
	ifstream in;
	in.open(f_name.c_str());

	if (in.is_open())
	{

		while (!in.eof())
		{
			in >> temp;
			vect.push_back(temp);
		}
	}
	else
	{
		cout << "Error. File could not be opened" << endl;
		exit(1);
	}

	// Close input stream
	in.close();
}

void readToFile(vector<double> &vect, string &f_name)
{

	ofstream out;

	// Write sorted elements to file
	out.open(f_name.c_str());

	if (out.is_open())
	{

		for (int i = 0; i < vect.size(); i++)
		{
			out << vect[i] << " ";

			// File will contain 30 numbers in each row
			if ((i != 0) && (i % 30 == 0))
				out << endl;
		}
		cout << "Sorted numbers written to " << f_name << endl;
	}
	else
	{
		cout << "Error. File could not be opened." << endl;
		exit(1);
	}

	// Close output stream
	out.close();
}
