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

using namespace std;

void swap_elements(double &x, double &y);

void ascending_order(vector<double> &vect);

void descending_order(vector<double> &vect);

void remove_duplicates(vector<double> &vect);

void read_from_file(vector<double> &vect, string &f_name);

void write_to_file(vector<double> &vect, string &f_name);



int main(int argc, char *argv[]) {

	namespace po = boost::program_options;

	// Declare the supported options
	po::options_description desc("Allowed options");
	desc.add_options()
		("help,h", "produce this message")
		("ascending,asc", "sort in ascending order")
		("descending,des", "sort in descending order")
		("remove_duplicates,rmd", "remove duplicates")
		("input,i", po::value<string>(), "name of input file")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);    

	if (vm.count("help")) {
   		cout << desc << "\n";
   		return 1;
	}
	

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

