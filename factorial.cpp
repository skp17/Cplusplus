#include <iostream>
#include <string>

using namespace std;

double factorial(int n) {

	if(n > 0)
		return n*factorial(n-1);
	else
		return 1;
}


int main() {
	
	int input;	

	cout << "Enter a positive interger" << endl;
	cin >> input;
	
	cout <<	input << "! = " << scientific << factorial(input) << endl;

	return 0;
}
