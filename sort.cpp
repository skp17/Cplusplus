#include <iostream>
#include <string>

using namespace std;

int main() {

double m_array[5] = {36, 21, 5, 81, 11};

long double min;
long double temp;

for(int i = 0; i < 5; i++) {
	
	min = &m_array[i];

	for(int j = i + 1; j < 5; j++) {
		
		if(m_array[j] < min)
			min = &m_array[j];
	}

	temp = &m_array[i];
	&m_array[i] = min;

}

return 0;
}
