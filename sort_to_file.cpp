

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;


void swap_elements(double &x, double &y);

void ascending_order(vector<double> &vect);

void descending_order(vector<double> &vect);

void read_from_file(vector<double> &vect, string &f_name);

void write_to_file(vector<double> &vect, string &f_name);



int main(int argc, char *argv[]) {

	extern char *optarg;
	extern int optind;
	int c, err = 0;
	int aflag = 0, dflag = 0; 	// aflag and dflag represent if the ascending 
					// and decsending options are parsed;
	char *iname, *fname = "sorted.dat";
	static char usage[] = "usage: sort [-ad] -i intput [-f output]\n";


	vector<double> v;
	string in_filename = "random.dat";
	string out_filename = "sorted_numbers.dat";

	// Read elements from file
	read_from_file(v, in_filename);

	// Sort elements in ascending order
	ascending_order(v);

	// Write sorted array to file
	write_to_file(v, out_filename);

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

