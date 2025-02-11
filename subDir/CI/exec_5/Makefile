


all: build build/test

build/test: test/test.cpp
	g++ test/test.cpp -I./lib/queue/ -lgtest -lgtest_main -o build/test

build:
	mkdir -p build

check:
	./build/test

.PHONY: check build all