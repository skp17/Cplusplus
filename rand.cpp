// Author: Steven Peters
// Date: August 2, 2019
// This program writes random numbers to a file

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {

	ofstream output;
	output.open("numbers.dat");
	int size = 3000; // Amount of numbers to write to file

	if( output.is_open() ) {
		output << size << endl; // First number inside file represents how many ramdom numbers inside file

		for(int i = 1; i <= size; i++) {
			output << rand()%1000 << " ";
			
			if( (i%30) == 0 )
				output << endl;
		}
		
	}
	else
		cout << "Error. File could not be opened." << endl;

	output.close();

	return 0;
}

