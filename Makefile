# Compile all .cpp files found inside this folder and put the
# executables inside ./Linux_executables

CXX = g++
CXXFLAGS = -std=c++11 -static
IDIR = /usr/local/boost_1_61_0
LDIR = $(IDIR)/bin.v2/libs/program_options/build/gcc-5.4.0/release/link-static/threading-multi/libboost_program_options.a
EDIR = ./Linux_executables

all:  factorial bfactorial fibonacci limits prime quadratic_roots rand sizeof sort bsort nperfect

factorial:
	$(CXX) factorial.cpp -o $(EDIR)/factorial
	
bfactorial:
	$(CXX) -I $(IDIR) bfactorial.cpp -o $(EDIR)/bfactorial
	
fibonacci:
	$(CXX) fibonacci.cpp -o $(EDIR)/fibonacci
	
limits:
	$(CXX) $(CXXFLAGS) limits.cpp -o $(EDIR)/limits
	
prime:
	$(CXX) prime.cpp -o $(EDIR)/prime
	
quadratic_roots:
	$(CXX) quadratic_roots.cpp -o $(EDIR)/quadratic_roots
	
rand:
	$(CXX) rand.cpp -o $(EDIR)/rand
	
sizeof:
	$(CXX) $(CXXFLAGS) sizeof.cpp -o $(EDIR)/sizeof
	
sort:
	$(CXX) $(CXXFLAGS) sort.cpp -o $(EDIR)/sort

bsort:
	$(CXX) -I $(IDIR) bsort.cpp -o $(EDIR)/bsort $(LDIR) $(CXXFLAGS)

nperfect:
	$(CXX) $(CXXFLAGS) nperfect.cpp -o $(EDIR)/nperfect

clean: 
	find . -maxdepth 1 -type f -executable -exec rm () +
