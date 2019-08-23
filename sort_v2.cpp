/* 
 * sort_v2.cpp
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
#include <stdlib.h>						/* for exit */
#include <unistd.h>						/* for getopt */
#include <boost/program_options.hpp>
#include <iomanip>						/* for setprecision */
#include <unordered_set>

using namespace std;
using namespace boost::program_options;

void remove_duplicates(vector<double> &vect);

void read_from_file(vector<double> &vect, string &f_name);

void write_to_file(vector<double> &vect, string &f_name);


int main(int argc, char *argv[]) {

	const float PRGM_VER = 2.0; 	// Program version
	string input_name, output_name;
	vector<double> m_vector; 	// This vector contains all numbers from the input file

	// Declare the supported options
	options_description desc("Allowed options");
	desc.add_options()
		("help,h", "produce this message")
		("version,v", "version of program")
		("ascending,a", "sort in ascending order")
		("descending,d", "sort in descending order")
		("remove_duplicates,r", "remove duplicates")
		("input,i", value<string>(&input_name), "name of input file")
	;

	// This option will be hidden from help message
	options_description hidden("Output option");
	hidden.add_options()
		("output", value<string>(&output_name)->default_value("sorted.dat"), "output file [default: ./sorted.dat]")
	;

	options_description all("Allowed options");
	all.add(desc).add(hidden);

	// Declare positional options
	positional_options_description p;
	p.add("output", 1);

	variables_map vm;
	store(command_line_parser(argc, argv).options(all).positional(p).run(), vm);
	notify(vm);

	cout << setprecision(1) << fixed;

	if(vm.count("help")) {
		cout << "Sort v" << PRGM_VER << ", a program that sorts numbers in either ascending"
			<< " or descending order,\nand removes duplicates if the user chooses.\n\n";
		cout << "Usage: " << argv[0] << " [-adr] -i input [output]\n\n";
   		cout << desc << "\n";
   		return 0;
	}

	if(vm.count("version")) {
		cout << "Sort v" << PRGM_VER << endl;
		return 0;
	}	

	if(vm.count("input")) {
		read_from_file(m_vector, input_name);
	}

	if(vm.count("ascending")) {
		sort(m_vector.begin(), m_vector.end());
	}

	if(vm.count("descending")) {
		sort(m_vector.begin(), m_vector.end(), greater<double>());
	}

	if(vm.count("remove_duplicates")) {
		remove_duplicates(m_vector);
	}

	if(vm.count("output")){
		write_to_file(m_vector, output_name);
	}

	return 0;
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

