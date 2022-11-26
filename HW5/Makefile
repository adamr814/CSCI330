#Adam Roy
#CSCI 330
#HW5 Makefile

all: hw5

hw5: hw5-scan.o hw5-load.o hw5-search.o hw5-free.o hw5-main.o
	gcc hw5-scan.o hw5-load.o hw5-search.o hw5-free.o hw5-main.o -o hw5

hw5-scan.o: hw5-scan.c hw5-scan.h
	gcc -O -c hw5-scan.c

hw5-load.o: hw5-load.c hw5-load.h
	gcc -O -c hw5-load.c

hw5-search.o: hw5-search.c hw5-search.h
	gcc -O -c hw5-search.c

hw5-free.o: hw5-free.c hw5-free.h
	gcc -O -c hw5-free.c

hw5-main.o: hw5-main.c
	gcc -O -c hw5-main.c

clean:
	rm -rf hw5
	rm -rf *.o