all: poly.o main.o
	gcc -o poly.app poly.o main.o

poly.o: poly.c poly.h
	gcc -c poly.c -Wall -Werror -pedantic -o poly.o

main.o: main.c
	gcc -c main.c -Wall -Werror -pedantic -o main.o
