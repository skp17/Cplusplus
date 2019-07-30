// Author: Steven Peters
// Date: July 30, 2019
// This program calculates the factorial of a number using iteration (for loop)

#include <iostream>
#include <string>

using namespace std;

int main() {

	unsigned int input;
	long double factorial;

	cout << "Enter a positive integer" << endl;
	cin >> input;

	factorial = (input)*(input-1);

	for(int i = (input - 2); i > 0; i--) {
		factorial = factorial * i;
	}

	cout << input << "! = " << factorial << endl;


	return 0;
}
