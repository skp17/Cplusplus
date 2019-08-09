// Author: Steven Peters
// Date: July 29, 2019
// This program sorts an array of numbers in ascending order


#include <iostream>
#include <string>

using namespace std;

void swap_elements(double &x, double &y) {
	double temp = x;
	x = y;
	y = temp;
}


int main(int argc, char* argv[]) {

int size = 10;
double m_array[size] = {12, 234, 23, 1, -7, 55, 18, 67, 99, 100};

for(int i = 0; i < size; i++) {
	for(int j = i + 1; j < size; j++) {
		
		if(m_array[j] < m_array[i])
			swap_elements(m_array[i], m_array[j]);
	}
}

cout << "The sorted array in ascending order is ";

for(int i = 0; i < size; i++)
  cout << m_array[i] << " ";

cout << endl; 

return 0;
}
