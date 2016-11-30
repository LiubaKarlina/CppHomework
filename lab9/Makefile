.PHONY: all clean

CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic

all: bin main

bin:
	mkdir -p bin

main: bin/main.o bin/matrix.o bin/shared_ptr.o
	g++ bin/main.o bin/matrix.o bin/shared_ptr.o -o main

bin/main.o: src/main.cpp include/shared_ptr.h
	g++ -c -I include src/main.cpp -o bin/main.o

bin/shared_ptr.o: src/shared_ptr.cpp include/matrix.h
	g++ -c -I include src/shared_ptr.cpp -o bin/shared_ptr.o

bin/matrix.o: src/matrix.cpp
	g++ -c -I include src/matrix.cpp -o bin/matrix.o

clean:
	rm -rf bin main

val:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main

run:
	./main
