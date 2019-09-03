# Compile all .cpp files found inside this folder and put the
# executables inside ./Linux_executables

CC = g++
CFLAGS = -std=c++11 -static
BOOST = /usr/local/boost_1_61_0/
PO_LBOOST = /usr/local/boost_1_61_0/bin.v2/libs/program_options/build/gcc-5.4.0/release/link-static/threading-multi/libboost_program_options.a


all:  factorial bfactorial fibonacci limits prime quadratic_roots rand sizeof sort bsort nperfect

factorial:
	${CC} factorial.cpp -o Linux_executables/factorial
	
bfactorial:
	${CC} -I ${BOOST} bfactorial.cpp -o Linux_executables/bfactorial
	
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
	${CC} ${CFLAGS} sizeof.cpp -o Linux_executables/sizeof
	
sort:
	${CC} ${CFLAGS} sort.cpp -o Linux_executables/sort

bsort:
	${CC} -I ${BOOST} bsort.cpp -o Linux_executables/bsort ${PO_LBOOST} ${CFLAGS}

nperfect:
	${CC} nperfect.cpp -o Linux_executables/nperfect

clean: 
	find . -maxdepth 1 -type f -executable -exec rm {} +
