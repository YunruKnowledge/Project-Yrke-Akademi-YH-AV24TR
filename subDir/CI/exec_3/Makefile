


all: build build/test

build/test: build/test.o build/greet.o 
	g++ build/test.o build/greet.o -I./lib/greet/ -lgtest -lgtest_main -o build/test

build/greet.o: lib/greet/greet.cpp lib/greet/greet.h
	g++ -c lib/greet/greet.cpp -I./lib/greet/ -o build/greet.o

build/test.o: test/test.cpp
	g++ -c test/test.cpp -I./lib/greet/ -lgtest -lgtest_main -o build/test.o

build:
	mkdir -p build

check:
	./build/test

.PHONY: check build all