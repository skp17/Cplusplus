// Author: Steven Peters
// Date: July 29, 2019
// This program sorts an array of numbers in descending order


#include <iostream>
#include <string>

using namespace std;

int main() {

int size = 10;
double m_array[size] = {12, 234, 23, 1, -7, 55, 18, 67, 99, 100};

double max;
double temp;
int position;
bool found; // True if a smaller number is found. Or else false.

for(int i = 0; i < size; i++) {
	
	max = m_array[i];
	found = false;

	for(int j = i + 1; j < size; j++) {
		
		if(m_array[j] > max) {
			max = m_array[j];
			position = j;
			found = true;
		}
	}

	if(found) {
		temp = m_array[i];
		m_array[i] = m_array[position];
		m_array[position] = temp;
	}
}

cout << "The sorted array in descending order is ";

for(int i = 0; i < size; i++)
  cout << m_array[i] << " ";

cout << endl; 

return 0;
}
