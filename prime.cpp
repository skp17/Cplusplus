/* File: prime.cpp
 * Name: Steven Peters
 * Date: August 22, 2019
 * Description: This program lets you know whether an integer is prime or not,
 *              as well as prints prime numbers.
*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <getopt.h>
#include <limits>
#include <stdlib.h>
//#include <cstdlib>
#include <iomanip>

using namespace std;

#define MINIMUM numeric_limits<unsigned int>::min()
#define MAXIMUM numeric_limits<unsigned int>::max()

void print_usage(string prog_name) {
    cerr << "usage: " << prog_name << " [-hv] [-c <integer>... | -p [-o <outfile>]]\n\n";
    cerr << "\t-h, --help \tDisplay this help message and exit\n";
    cerr << "\t-v, --version \tDisplay program version\n";
    cerr << "\t-c, --check \tLets the user know if an integer is prime or not\n";
    cerr << "\t-p, --print \tPrints prime numbers\n";
    cerr << "\t-o, --output \tWrites prime numbers to a file\n";
}

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

void getArgsList(int argc, char *argv[], int optind) {
    while (optind < argc) {
        unsigned int integer = atoi(argv[optind]);
        if (integer > MINIMUM && integer < MAXIMUM) {
            if (isPrime(integer))
                cout << integer << " is a prime number" << endl;
            else
                cout << integer << " is not a prime number" << endl;
        }
        else
            cout << "The input " << argv[optind] << " is either out of bounds or invalid\n";

        optind++;
    }
}

void printPrimes(unsigned int amount) {
    cout << "Prime numbers:\n";
    unsigned int count = 0;
    for (unsigned int i = 2; (count < amount); i++) {
        if (isPrime(i)) {
                cout << i << " ";
                count++;
        }
    }
    cout << endl;
}

bool writeToFile(unsigned int amount, string f_name) {
    ofstream outfile;
    outfile.open(f_name.c_str());
    if (outfile.is_open()) {
        unsigned int count = 0;
        for (unsigned int i = 2; (count < amount); i++) {
            if (isPrime(i)) {
                outfile << i << " ";
                count++;
            }
        }
        outfile.close();
        cout << "Prime numbers successfully written to " << f_name << endl;
        return true;
    }
    else
    {
        cerr << "Issue opening file\n";
        return false;
    }
}

int main(int argc, char *argv[]) {

    const float PRGM_VER = 2.0;     // Program version
    const string PGRM_NM = argv[0]; // Program name
    int cflag = 0, pflag = 0, oflag = 0;
    unsigned int amount;
    string filename = "";
    int c;

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'v'},
            {"check", required_argument, 0, 'c'},
            {"print", required_argument, 0, 'p'},
            {"output", required_argument, 0, 'o'},
            {0, 0, 0, 0},
        };

        c = getopt_long(argc, argv, "hvc:p:o:", long_options, &option_index);

        /* Detect the end of the options */
        if (c == -1)
            break;

        switch (c) {
            case 'h':
                print_usage(PGRM_NM);
                exit(0);
            case 'v':
                cout << PGRM_NM << " v" << setprecision(1) << fixed << PRGM_VER << endl;
                exit(0);
            case 'c':
                cflag = 1;
                getArgsList(argc, argv, optind-1); 
                break;
            case 'p':
                pflag = 1;
                amount = atoi(optarg);
                break;
            case 'o':
                oflag = 1;
                filename = optarg;
                break;
            case '?':
                print_usage(PGRM_NM);
                exit(1);
            default:
			    abort();
        }

    }

    if (pflag && !oflag)
        printPrimes(amount);
    
    if(oflag) {
        if (pflag) {
            if (filename != "")
                writeToFile(amount, filename);
            else
                cerr << "Missing output file\n";
        }
        else {
            cerr << "Missing --print option\n";
            exit(1);
        }
    }

    if (cflag && pflag) {
        cerr << "Choose -c to check primality of integers or -p to print primes. Not both!";
        exit(1);
    }

    if(argc == 1) {
        cout << "How many prime numbers do you want to see? ";
        cin >> amount;
        printPrimes(amount);
    }

    return 0;
}