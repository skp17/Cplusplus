// Author: Steven Peters
// July 17, 2019
// This program displays prime numbers
// Your input determines how many prime numbers to show


#include <iostream>
#include <string>

using namespace std;

int main() {
 
 int limit; 		// How many prime numbers to display
 bool is_prime;		// Indicates if number is prime or not
 int count = 0; 	// Number of primes found
 
 cout << "How many prime numbers do you want to see? ";
 cin >> limit;
 cout << "\nPrime numbers: ";

 if(limit > 0) {
	 for(int i = 2; count < limit; i++) {
		is_prime = true; // Number is marked as prime until proven false
		for(int j = 2; ((j < i) && (is_prime == true)); j++) {

			if( (i % j) == 0 ) {
				is_prime = false;
			}		
		}

		if(is_prime == true) {
			cout << i << " ";
			count++;
		}
 	}
 }
 else
	cout << "Please enter a number equal or greater than 1." << endl;

 cout << endl;

 return 0;
}
