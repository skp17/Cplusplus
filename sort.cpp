#include <iostream>
#include <string>

using namespace std;

int main() {

double m_array[5] = {36, 21, 5, 81, 11};

double min;
double temp;
int j, position;

for(int i = 0; i < 5; i++) {
	
	min = m_array[i];

	for(j = i + 1; j < 5; j++) {
		
		if(m_array[j] < min) {
			min = m_array[j];
			position = j;
		}
	}

	temp = m_array[i];
	m_array[i] = m_array[position];
	m_array[position] = temp;

}

cout << "The sorted array is ";

for(int i = 0; i < 5; i++)
  cout << m_array[i] << " ";

cout << endl; 

return 0;
}
