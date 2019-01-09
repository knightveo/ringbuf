CC ?= cc
CPPFLAGS ?= -Iinclude
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all test clean
all: examples/basic

build:
	mkdir -p build

build/ringbuf.o: src/ringbuf.c include/ringbuf.h | build
	$(CC) $(CPPFLAGS) $(CFLAGS) -c src/ringbuf.c -o $@

examples/basic: examples/basic.c build/ringbuf.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

build/test_ringbuf: tests/test_ringbuf.c build/ringbuf.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test: build/test_ringbuf
	./build/test_ringbuf

clean:
	rm -rf build examples/basic