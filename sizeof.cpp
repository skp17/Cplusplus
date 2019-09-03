// Author: Steven Peters
// This program displays of size of all data types


#include <iostream>
#include <string>

using namespace std;

int main() {

cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
cout << "Size of char: " << sizeof(char) << " byte" << endl;
cout << "Size of short int: " << sizeof(short int) << " bytes" << endl;
cout << "Size of int: " << sizeof(int) << " bytes" << endl;
cout << "Size of long int: " << sizeof(long int) << " bytes" << endl;
cout << "Size of long long int: " << sizeof(long long int) << " bytes" << endl;
cout << "Size of float: " << sizeof(float) << " bytes" << endl;
cout << "Size of double: " << sizeof(double) << " bytes" << endl;
cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;

return 0;
}
