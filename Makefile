CC=gcc
CFLAGS=-Wall -Werror -std=c11 -g
OBJ=main.o \
    buffer.o \
    meta.o \
    state.o \
    table.o

main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c buffer.h meta.h state.h
	$(CC) $(CFLAGS) -c $< -o $@

buffer.o: buffer.c
	$(CC) $(CFLAGS) -c $< -o $@

meta.o: meta.c buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

state.o: state.c buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

table.o: table.c buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o main
