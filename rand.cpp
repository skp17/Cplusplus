// Author: Steven Peters
// Date: August 2, 2019
// This program writes random numbers to a file

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

	srand(time(0)); // Use current time as seed for random generator 

	string filename;
	ofstream output;
	unsigned int size = 3000; // Amount of numbers to write to file

	if(argc < 0) {
		cerr << "Usage: " << argv[0] << " Filename" << endl;
		return 1;
	}

	// If user doesn't input a filename then use default
	if(argc == 1) {
		filename = "random.dat";
	}

	// If user inputs a filename
	if(argc == 2) {
		filename = argv[1];
	}

	output.open(filename.c_str());

	if( output.is_open() ) {
		for(unsigned int i = 1; i <= size; i++) {
			output << rand()%1000 << " ";
			
			if( (i%30) == 0 )
				output << endl;
		}

		cout << "Random numbers written to " << filename << endl;
	}
	else
		cout << "Error. File could not be opened." << endl;

	output.close();

	return 0;
}

