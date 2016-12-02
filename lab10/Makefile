.PHONY: all clean

CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic

all: bin main

bin:
	mkdir -p bin

main: bin/main.o bin/figure.o bin/scheme.o bin/rectangle.o bin/circle.o
	g++ bin/main.o bin/figure.o bin/scheme.o bin/rectangle.o bin/circle.o -o main

bin/main.o: src/main.cpp include/scheme.h include/rectangle.h include/circle.h
	g++ -c -I include src/main.cpp -o bin/main.o

bin/scheme.o: src/scheme.cpp include/figure.h
	g++ -c -I include src/scheme.cpp -o bin/scheme.o

bin/rectangle.o: src/rectangle.cpp include/figure.h
	g++ -c -I include src/rectangle.cpp -o bin/rectangle.o

bin/circle.o: src/circle.cpp include/figure.h
	g++ -c -I include src/circle.cpp -o bin/circle.o

bin/figure.o: src/figure.cpp
	g++ -c -I include src/figure.cpp -o bin/figure.o

clean:
	rm -rf bin main

val:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main

run:
	./main
