#include "ringbuf.h"
#include <assert.h>
#include <stdio.h>

static void test_empty_and_full(void) {
    uint8_t storage[3];
    ringbuf_t rb;
    assert(ringbuf_init(&rb, storage, 3));
    assert(ringbuf_empty(&rb));
    assert(ringbuf_push(&rb, 10));
    assert(ringbuf_push(&rb, 20));
    assert(ringbuf_push(&rb, 30));
    assert(ringbuf_full(&rb));
    assert(!ringbuf_push(&rb, 40));
}

static void test_wraparound(void) {
    uint8_t storage[2];
    uint8_t value = 0;
    ringbuf_t rb;
    assert(ringbuf_init(&rb, storage, 2));
    assert(ringbuf_push(&rb, 1));
    assert(ringbuf_push(&rb, 2));
    assert(ringbuf_pop(&rb, &value) && value == 1);
    assert(ringbuf_push(&rb, 3));
    assert(ringbuf_pop(&rb, &value) && value == 2);
    assert(ringbuf_pop(&rb, &value) && value == 3);
    assert(ringbuf_empty(&rb));
}

int main(void) {
    test_empty_and_full();
    test_wraparound();
    puts("ok");
    return 0;
}