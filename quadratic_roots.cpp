// Author: Steven Peters
// July 21, 2019

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

double a, b, c; // Quadratic coefficients
double root1, root2;

cout << "Enter the coefficients of the quadratic equation ax*x + bx + c = 0" << endl;
cin >> a >> b >> c;

double discriminant = (b*b) - 4*a*c;

if(a!=0) {
	if(discriminant >= 0) {
		if(discriminant == 0) {
			root1 = -b/(2*a);
			cout << "The equation has 1 real root:\nx = " << root1 << endl;
		}
	
		if(discriminant > 0) {
			root1 = -b/(2*a) - sqrt(discriminant)/(2*a);
			root2 = -b/(2*a) + sqrt(discriminant)/(2*a);
			cout << "The equation has 2 real roots:\nx = " << root1 << "\nx = " << root2 << endl;
		}
	}

	if(discriminant <= 0) {
		double real = -b/(2*a);			
		double imaginary = sqrt( fabs(discriminant) ) / (2*a);
		cout << "The equation has complex roots: \nx = " << real << " + " << imaginary << "i"
			<< "\nx = " << real << " - " << imaginary << "i" << endl;
	}
}
else
	cout << "The coefficient 'a' cannot equal zero" << endl;


return 0;
}
