run: all
	clear
	./main

all:
	gcc -Wall -c */*.c
	gcc -Wall -c *.c
	gcc -o main *.o
	clear

clean:
	rm -f *.o
	rm -f main
	clear