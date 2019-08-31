// Author: Steven Peters
// This program displays of size of all data types and ranges


#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {

cout << scientific;

cout << setw(10) << "Data type" << setw(23) << "Size (bytes)" << setw(21) << "Range" << endl;
cout << string(65, '-') << endl;

cout << "signed char" << setw(15) << sizeof(signed char) << setw(23) << static_cast<int>(numeric_limits<signed char>::min()) << " to " 
	<< static_cast<int>(numeric_limits<signed char>::max()) << endl;

cout << "unsigned char" << setw(13) << sizeof(unsigned char) << setw(23) << static_cast<int>(numeric_limits<unsigned char>::min()) << " to " 
	<< static_cast<int>(numeric_limits<unsigned char>::max()) << endl;

cout << "signed short int" << setw(10) << sizeof(short int) << setw(23) << (double)numeric_limits<signed short int>::min() << " to " << (double)numeric_limits<signed short int>::max() << endl;

cout << "unsigned short int" << setw(8) << sizeof(unsigned short int) << setw(23) << numeric_limits<unsigned short int>::min() << " to " <<(double)numeric_limits<unsigned short int>::max() << endl;

cout << "signed int" << setw(16) << sizeof(int) << setw(23) << (double)numeric_limits<int>::min() << " to " << (double)numeric_limits<int>::max() << endl;

cout << "unsigned int" << setw(14) << sizeof(unsigned int) << setw(23) << numeric_limits<unsigned int>::min() << " to " << (double)numeric_limits<unsigned int>::max() << endl;

cout << "signed long int" << setw(11) << sizeof(long int) << setw(23) << (double)numeric_limits<long int>::min() << " to " << (double)numeric_limits<long int>::max() << endl;

cout << "unsigned long int" << setw(9) << sizeof(unsigned long int) << setw(23) << numeric_limits<unsigned long int>::min() << " to " << (double)numeric_limits<unsigned long int>::max() << endl;

cout << "signed long long int" << setw(6) << sizeof(long long int) << setw(23) << (double)numeric_limits<long long int>::min() << " to " << (double)numeric_limits<long long int>::max() << endl;

cout << "unsigned long long int" << setw(4) << sizeof(unsigned long long int) << setw(23) << numeric_limits<unsigned long long int>::min() << " to " << (double)numeric_limits<unsigned long long int>::max() << endl;

cout << "float" << setw(21) << sizeof(float) << setw(23) << numeric_limits<float>::min() << " to " << numeric_limits<float>::max() << endl;

cout << "double" << setw(20) << sizeof(double) << setw(23) << numeric_limits<double>::min() << " to " << numeric_limits<double>::max() << endl;

cout << "long double" << setw(15) << sizeof(long double) << setw(23) << numeric_limits<long double>::min() << " to " << numeric_limits<long double>::max() << endl;

cout << endl;

return 0;
}
