


build/app: build/main.o
	g++ build/main.o -o build/app

build/main.o: main.c strintergers.h
	g++ -c main.c -o build/main.o

build/unity.o: unity/unity.cpp unity/unity.h
	g++ -c unity/unity.cpp -I./unity -o build/unity.o

build/test.o: test.c build/unity.o
	g++ -c test.c -I./unity -o build/test.o

check: build/test.o
	g++ build/test.o build/unity.o -o build/test
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