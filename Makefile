all:
	gcc -Wall -c */*.c
	gcc -Wall -c *.c
	gcc -o main *.o

run:
	clear
	@./main

clean:
	rm -f *.o
	rm -f main
	clear
