# ringbuf

A small fixed-capacity ring buffer in C with explicit wraparound, full/empty state, and ownership semantics.

## API

    ringbuf_init(&rb, storage, capacity);
    ringbuf_push(&rb, value);
    ringbuf_pop(&rb, &value);

The implementation keeps head, 	ail, and count explicit. Writes fail when the buffer is full rather than silently overwriting unread data.

## Build

    make
    make test
    ./examples/basic

## Layout

- include/ringbuf.h - public API
- src/ringbuf.c - implementation
- 	ests/test_ringbuf.c - wraparound/full/empty cases
- examples/basic.c - minimal usage example
