#ifndef RINGBUF_H
#define RINGBUF_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;
} ringbuf_t;

bool ringbuf_init(ringbuf_t *rb, uint8_t *storage, size_t capacity);
bool ringbuf_push(ringbuf_t *rb, uint8_t value);
bool ringbuf_pop(ringbuf_t *rb, uint8_t *value);
size_t ringbuf_size(const ringbuf_t *rb);
bool ringbuf_empty(const ringbuf_t *rb);
bool ringbuf_full(const ringbuf_t *rb);

#endif