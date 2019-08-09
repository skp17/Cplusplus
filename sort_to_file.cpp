

#include <iostream>
#include <fstream>

using namespace std;


void swap_elements(double &x, double &y);

void ascending_order(double *arr, int arr_size);

int read_from_file(double *arr);

void write_to_file(double *arr, int arr_size, string &f_name);



int main() {

	double *array;
	string in_filename = "numbers.dat";
	string out_filename = "sorted_numbers.dat";
	unsigned int size; // Represents number of elements in file

	// Read elements from file and return size
	size = read_from_file(array);

	// Sort elements in ascending order
	ascending_order(array, size);

	// Write sorted array to file
	write_to_file(array, size, out_filename);

	return 0;
}


void swap_elements(double &x, double &y) {
	double temp = x;
	x = y;
	y = temp;
}

void ascending_order(double *arr, int arr_size) {

	for(int i = 0; i < arr_size; i++) {
		for(int j = i + 1; j < arr_size; j++) {

			if(arr[j] < arr[i])
				swap_elements(arr[i], arr[j]);
		}
	}
}

int read_from_file(double *arr) {

	int arr_size;
	ifstream in;
	in.open("src/numbers.dat");

	if( in.is_open() ) {

		in >> arr_size; // First number in file represents number of elements.
		arr = new double [arr_size];

		while ( !in.eof() ) {
			for(int i = 0; i < arr_size; i++) {
				in >> arr[i];
			}
		}

	}
	else
		cout << "Error. File could not be opened" << endl;

	in.close();

	return arr_size;
}

void write_to_file(double *arr, int arr_size, string &f_name) {

	ofstream out;

	// Write sorted elements to file
	out.open(f_name.c_str());

	if( out.is_open() ) {
		out << arr_size << endl; // First number inside file represents how many ramdom numbers inside file

		for(int i = 0; i < arr_size; i++) {
			out << arr[i] << " ";

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

