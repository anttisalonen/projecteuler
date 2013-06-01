CXXFLAGS=-std=c++11 -Wall -O2

default: all tests

all: problem1/main problem2/main problem3/main problem4/main problem5/main \
	problem6/main problem7/main problem8/main problem9/main \
	problem10/main

.PHONY: tests clean

tests: test1 test2 test3 test4 test5

libs: lib/args.cpp lib/prime.cpp

test1: problem1/main
	$< 10
	$< 1000

test2: problem2/main
	$< 4000000

test3: problem3/main
	$< 13195
	$< 600851475143

test4: problem4/main
	$< 2
	$< 3

test5: problem5/main
	$< 10
	$< 20

test6: problem6/main
	$< 10
	$< 100

test7: problem7/main
	$< 6
	$< 10001

test8: problem8/main
	$< 0

test9: problem9/main
	$< 0

test10: problem10/main libs
	$< 10
	$< 2000000

clean:
	rm -f problem*/main
