// Author: Steven Peters
// Date: August 2, 2019
// This program removes duplicate numbers in an array

#include <iostream>
#include <string>

using namespace std;


void print_array(double array[], double size);

void delete_element(double array[], int size, int index);


int main() {

	int size = 10;
	double m_array[size] = {12, 234, 12, 1, -7, 55, -7, 67, 99, 1};

	for(int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			
			if(m_array[i] == m_array[j]) {
				delete_element(m_array, size, j);
				size--;
			}
		}
		
	}


	print_array(m_array, size);

	return 0;
}



void print_array(double array[], double size) {

	for(int i = 0; i < size; i++)
		cout << array[i] << " ";

	cout << endl;
}


void delete_element(double array[], int size, int index) {

	for(int i = index; i < size-1; i++) {
		array[i] = array[i + 1];
	}
}

