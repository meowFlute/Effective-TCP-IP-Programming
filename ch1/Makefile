# Chapter 1 Makefile:
# This chapter just creates a very simple client and server
CC=clang
CFLAGS=-g -Wall -Wextra -std=gnu99 -fsanitize=address,undefined

.PHONY: all clean check

all: simple_server simple_client

simple_server: simple_server.c
	$(CC) $(CFLAGS) -o $@ $^

simple_client: simple_client.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf simple_server simple_client

DANGEROUS_FUNCTIONS:='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo 'Files with potentially dangerous functions:'
	@egrep "$(DANGEROUS_FUNCTIONS)" simple_server.c || true
	@egrep "$(DANGEROUS_FUNCTIONS)" simple_client.c || true
