/* 
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
#include <boost/program_options.hpp>
#include <iomanip>

using namespace std;
using namespace boost::program_options;

void swap_elements(double &x, double &y);

void ascending_order(vector<double> &vect);

void descending_order(vector<double> &vect);

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
		("output-file", value<string>(&output_name)->default_value("sorted.dat"), "output file")
	;

	variables_map vm;
	store(parse_command_line(argc, argv, desc), vm);

	// Declare positional options
	positional_options_description p;
	p.add("output-file", -1);
	store(command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
	notify(vm);

	read_from_file(m_vector, input_name);

	cout << setprecision(1) << fixed;

	if(vm.count("help")) {
		cout << "Sort " << PRGM_VER << ", a program that sorts numbers in either ascending"
			<< " or descending order, and removes duplicates if the user chooses.\n\n";
		cout << "Usage: " << argv[0] << " [-adr] -i input [output]\n\n";
   		cout << desc << "\n";
   		return 1;
	}

	if(vm.count("version")) {
		cout << "Sort " << PRGM_VER << endl;
	}

	if(vm.count("ascending")) {
		ascending_order(m_vector);
	}

	if(vm.count("descending")) {
		descending_order(m_vector);
	}

	if(vm.count("remove_duplicates")) {
		remove_duplicates(m_vector);
	}

	write_to_file(m_vector, output_name);

	return 0;
}

void swap_elements(double &x, double &y) {
	double temp = x;
	x = y;
	y = temp;
}

void ascending_order(vector<double> &vect) {

	for(int i = 0; i < vect.size(); i++) {
		for(int j = i + 1; j < vect.size(); j++) {

			if(vect[j] < vect[i])
				swap_elements(vect[i], vect[j]);
		}
	}
}

void descending_order(vector<double> &vect) {

	for(int i = 0; i < vect.size(); i++) {
		for(int j = i + 1; j < vect.size(); j++) {

			if(vect[j] > vect[i])
				swap_elements(vect[i], vect[j]);
		}
	}
}

void remove_duplicates(vector<double> &vect) {

	for(int i = 0; i < vect.size(); i++) {
		for(int j = i + 1; j < vect.size(); j++) {

			if(vect[i] == vect[j])
				vect.erase(vect.begin() + j);
		}
	}
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

