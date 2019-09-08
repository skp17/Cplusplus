/* File: nperfect.cpp
 * Name: Steven Peters
 * Date: August 10, 2019
 * Description: This program prints out 'n' perfect numbers
 *              where 'n' is the user input.
 *              A perfect number is a positive integer that is equal 
 *              to the sum of its positive divisors, excluding the number itself.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(unsigned int n) {
    bool flag = true;
    if (n < 2)
        flag = false;
    else if (n == 2)
        flag = true;
    else if (n%2 == 0)
        flag = false;
    else {
        for (unsigned int i = 3; i < n; i+=2) {
            if (n%i == 0) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {

    unsigned int limit;
    unsigned int count = 0;
    unsigned long long int perfectNum; 
    cout << "How many perfect numbers do you want displayed?\n";
    cin >> limit;
    cout << "Perfect numbers:\n";

    for (unsigned int i = 2; count < limit; i++) {
        if (isPrime(i)) {
            perfectNum = pow(2.0, i-1)*( pow(2,i) - 1);
            count++;

            /* if large enough output in scientific natation */
            if (perfectNum < 9999.0)
                cout << perfectNum << " ";
            else
                cout << scientific << (double)perfectNum << " ";
        }
    }

    cout << endl;

    return 0;
}