// Author: Steven Peters
// July 16, 2019
// This program displays Fibonacci numbers
// Your input determines how many Fibonacci numbers to show


#include <iostream>
#include <string>

using namespace std;

int main() {

 unsigned long long int previous = 1;
 unsigned long long int current = 1;
 unsigned long long int sum;
 int count;

 cout << "How many fibonacci numbers do you want to see?" << endl;
 cin >> count;

 cout << previous << " " << current << " ";

 for(int i = 3; i <= count; i++) {
 	sum = previous + current;
	cout << sum << " ";
	previous = current;
	current = sum;
 }

 cout << endl;

 return 0;
}
