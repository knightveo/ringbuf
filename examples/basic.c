#include "ringbuf.h"
#include <stdio.h>

int main(void) {
    uint8_t storage[4];
    uint8_t value;
    ringbuf_t rb;

    ringbuf_init(&rb, storage, 4);
    ringbuf_push(&rb, 7);
    ringbuf_push(&rb, 11);

    while (ringbuf_pop(&rb, &value)) printf("%u\n", (unsigned)value);
    return 0;
}