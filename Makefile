CC=gcc
CFLAGS=-Wall -Werror -std=c11 -g

main: main.o buffer.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

buffer.o: buffer.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o main
