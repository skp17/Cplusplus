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

using namespace std;

bool isPerfect(unsigned long long int num) {

    // Add up the divisors
    unsigned long long sum = 0;
        for (int i = 1; i <= num/2; i++) {
            if (num % i == 0)
                sum = sum + i; 
        }

    // If sum of divisors equal num, then return true
        if (sum == num)
            return true;
        else
            return false;   
}

int main() {

    unsigned int count = 0;
    unsigned long long number = 1;
    unsigned int amount;

    cout << "Enter the amount of perfect numbers you want to be displayed\n";
    cin >> amount;
    cout << "Perfect numbers: ";

    while (count < amount) {
        if ( isPerfect(number) ) {
            count++;
            cout << number << " ";
        }
        number++;
    }

    return 0;
}