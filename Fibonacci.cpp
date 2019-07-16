#include <iostream>
#include <string>

using namespace std;

int main() {

 int previous = 1;
 int current = 1;
 int sum;
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
