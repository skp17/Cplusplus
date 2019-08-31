# Compile all .cpp files found inside this folder and put the
# executables inside ./Linux_executables

CC = g++
CFLAGS = -std=c++11 -static
BOOST = /usr/local/boost_1_61_0/
LIBBOOST = /usr/local/boost_1_61_0/bin.v2/libs/program_options/build/gcc-5.4.0/release/link-static/threading-multi/libboost_program_options.a


all:  factorial bfactorial fibonacci limits prime quadratic_roots rand sizeof sort bsort

factorial:
	${CC} factorial.cpp -o Linux_executables/factorial
	
factorial2:
	${CC} factorial2.cpp -o Linux_executables/factorial2
	
fibonacci:
	${CC} fibonacci.cpp -o Linux_executables/fibonacci
	
limits:
	${CC} ${CFLAGS} limits.cpp -o Linux_executables/limits
	
prime:
	${CC} prime.cpp -o Linux_executables/prime
	
quadratic_roots:
	${CC} quadratic_roots.cpp -o Linux_executables/quadratic_roots
	
rand:
	${CC} rand.cpp -o Linux_executables/rand
	
sizeof:
	${CC} sizeof.cpp -o Linux_executables/sizeof
	
sort:
	${CC} ${CFLAGS} sort.cpp -o Linux_executables/sort

bsort:
	${CC} -I ${BOOST} bsort.cpp -o Linux_executables/bsort ${LIBBOOST} ${CFLAGS}

clean: 
	rm factorial factorial2 fibonacci limits prime quadratic_roots rand sizeof sort bsort
