

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void swap_elements(double &x, double &y) {
	double temp = x;
	x = y;
	y = temp;
}

int main() {

	ifstream input;
	ofstream output;
	double *array;
	unsigned int size; // Represents number of elements in file

	// Read elements from file
	input.open("numbers.dat"); // Open input stream

	if( input.is_open() ) {

		input >> size; // First number in file represents number of elements.
		array = new double [size];

		while ( !input.eof() ) {
			for(int i = 0; i < size; i++) {
				input >> array[i];
			}
		}

	}
	else
		cout << "Error. File could not be opened" << endl;

	// Close input stream
	input.close();
	
	
	// Sort elements in ascending order
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			
			if(array[j] < array[i])
				swap_elements(array[i], array[j]);
			}
	}


	// Write sorted elements to file
	output.open("sorted_numbers.dat");

	if( output.is_open() ) {
		output << size << endl; // First number inside file represents how many ramdom numbers inside file

		for(int i = 0; i < size; i++) {
			output << array[i] << " ";
			
			if( ( (i+1) % 30 ) == 0 )
				output << endl;
		}	
	}
	else
		cout << "Error. File could not be opened." << endl;

	// Close output stream	
	output.close();

	return 0;
}
