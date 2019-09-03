/* File: isPrime.cpp
 * Name: Steven Peters
 * Date: August 22, 2019
 * Description: This program lets you know whether an integer is prime or not
*/ 

#include <iostream>
#include <string>
#include <getopt.h>
#include <limits>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

#define MINIMUM numeric_limits<unsigned int>::min()
#define MAXIMUM numeric_limits<unsigned int>::max()

void print_usage(string prog_name) {
    cerr << "usage: " << prog_name << " [-h] <integer>...\n\n";
    cerr << "\t-h, --help \tDisplay this help message and exit\n";
}

int main(int argc, char *argv[]) {

    string program_name = argv[0];
    int c;
    unsigned int integer;

    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {0, 0, 0, 0},
        };

        c = getopt_long(argc, argv, "h", long_options, &option_index);

        /* Detect the end of the options */
        if (c == -1)
            break;

        switch (c) {
            case 'h':
                print_usage(program_name);
                exit(1);
            case '?':
                print_usage(program_name);
                exit(1);
            default:
			    abort();
        }

    }

    if (optind < argc) {
        while (optind < argc) {
            integer = atoi(argv[optind++]);
            cout << integer << endl;
        }
    }

    return 0;
}