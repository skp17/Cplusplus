This repository contains executibles for Linux and for Windows
operating systems.

# Dependencies
* boost c++ libraries (for factorial and bsort programs)

# Makefiles
On Windows, programs can be built using the command line tool NMAKE, which is included in Visual Studio. To use NMAKE, you must run it in a Developer Command Prompt window using the following command
```cmd
nmake -f Makefile.win
```


# fibonacci.cpp
    Displays Fibonacci numbers. Your input determines how many Fibonacci numbers to show.

# sizeof.cpp
    Displays of size of all data types.

# limits.cpp
    Displays of size of all data types and ranges.

# quadratic_roots.cpp
    Calculates the roots of a quadratic function.

# factorial.cpp (Uses BOOST libraries)
    Calculates the factorial of a number using recursion.
    Boost/multiprecision library is used for larger ranges

# nperfect.cpp
    Prints out 'n' perfect numbers where 'n' is the user input. 
>A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.

# rand.cpp
    Writes random numbers to a file. Run this program to test sort.cpp
## usage
```bash
$ ./rand --help
usage: ./rand [-s <n>] [<outfile>]

        -h, --help      Print this help message and exit
        -s, --size <n>  Amount of random numbers to produce [default: 3000]
            <outfile>   output file [default: numbers.dat]
```

# sort.cpp
    Takes as input a file containing numbers and arranges them in either ascending or descending order, as well as removes duplicates according to the user's input commands.
## usage
```bash
$ ./sort --help
usage: ./sort [-a|d] [r] -i <infile> [<outfile>]

        -a, --ascending                 ascending order
        -d, --descending                descending order
        -r, --remove_duplicates         remove duplicates
        -i, --input <infile>            input file
            <outfile>                   output file [default: sorted.dat]
        -h, --help                      display this message
        -v, --version                   display program version
```

# bsort.cpp (Uses BOOST libraries)
    This program does the same thing that sort.cpp does except it uses boost/program_options to parse command line arguments.
## usage
```bash
$ ./bsort --help
Sort v2.0, a program that sorts numbers in either ascending or descending order,
and removes duplicates if the user chooses.

Usage: ./bsort [-a|-d] [r] -i <input> [<output>]

Allowed options:
  -h [ --help ]               produce this message
  -v [ --version ]            version of program
  -a [ --ascending ]          sort in ascending order
  -d [ --descending ]         sort in descending order
  -r [ --remove_duplicates ]  remove duplicates
  -i [ --input ] arg          name of input file
```

# prime.cpp
    Prints out prime numbers. Also lets you know whether an integer is prime or not. 
## usage
```bash
$ ./prime --help
usage: ./prime [-hv] [-c <integer>... | -p [-o <outfile>]]

        -h, --help      Display this help message and exit
        -v, --version   Display program version
        -c, --check     Lets the user know if an integer is prime or not
        -p, --print     Prints prime numbers
        -o, --output    Writes prime numbers to a file
```



