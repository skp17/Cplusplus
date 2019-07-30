// Author: Steven Peters
// Date: July 30, 2019
// This program calculates the factorial of a number using recursion

#include <iostream>
#include <string>

using namespace std;

long double factorial(int n) {

	if(n > 0)
		return n*factorial(n-1);
	else
		return 1;
}


int main() {
	
	int input;	

	cout << "Enter a positive integer" << endl;
	cin >> input;

	cout <<	input << "! = " << scientific << factorial(input) << endl;

	return 0;
}
