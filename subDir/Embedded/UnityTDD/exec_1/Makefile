


build/app: build/main.o build/fizzbuzz.o
	g++ build/main.o build/fizzbuzz.o -o build/app

build/main.o: src/main.c lib/fizzbuzz/fizzbuzz.h
	g++ -c src/main.c -I./lib/fizzbuzz -o build/main.o

build/fizzbuzz.o: lib/fizzbuzz/fizzbuzz.c lib/fizzbuzz/fizzbuzz.h
	g++ -c lib/fizzbuzz/fizzbuzz.c -I./lib/fizzbuzz -o build/fizzbuzz.o

build/unity.o: lib/unity/unity.cpp lib/unity/unity.h
	g++ -c lib/unity/unity.cpp -I./lib/unity -o build/unity.o

build/test.o: test/test.c build/unity.o
	g++ -c test/test.c -I./lib/unity -I./lib/fizzbuzz -o build/test.o

check: build/unity.o build/test.o build/fizzbuzz.o
	g++ build/test.o build/unity.o build/fizzbuzz.o -o build/test
	./build/test

w_run:
	./build/app.exe

run:
	./build/app

w_build:
	mkdir build

build:
	mkdir -p build

clean: 
	rm -f build/*.o
	rm -f build/app
	rm -f build/test
	rm -d build/

.PHONY: build clean run