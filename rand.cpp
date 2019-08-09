// Author: Steven Peters
// Date: August 2, 2019
// This program writes random numbers to a file

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {

	srand(time(0)); // Use current time as seed for random generator 

	const char* filename = "numbers.dat";
	ofstream output;
	output.open(filename);
	int size = 3000; // Amount of numbers to write to file

	if( output.is_open() ) {
		output << size << endl; // First number inside file represents how many ramdom numbers inside file

		for(int i = 1; i <= size; i++) {
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

