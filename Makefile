all:
  gcc -g -Wall -o wtc *.c -lpthread
	
clean:
	rm -f wtc

