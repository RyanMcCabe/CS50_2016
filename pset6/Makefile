#
# Makefile
#
# Computer Science 50
# Problem Set 6
#
all: server

server: server.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o server server.c -lm

clean:
	rm -f *.o core server
