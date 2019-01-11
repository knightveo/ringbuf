#include "ringbuf.h"

bool ringbuf_init(ringbuf_t *rb, uint8_t *storage, size_t capacity) {
    if (!rb || !storage || capacity == 0) return false;
    rb->data = storage;
    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
    return true;
}

bool ringbuf_push(ringbuf_t *rb, uint8_t value) {
    if (!rb || ringbuf_full(rb)) return false;
    rb->data[rb->tail] = value;
    rb->tail = (rb->tail + 1) % rb->capacity;
    rb->count++;
    return true;
}

bool ringbuf_pop(ringbuf_t *rb, uint8_t *value) {
    if (!rb || !value || ringbuf_empty(rb)) return false;
    *value = rb->data[rb->head];
    rb->head = (rb->head + 1) % rb->capacity;
    rb->count--;
    return true;
}

size_t ringbuf_size(const ringbuf_t *rb) { return rb ? rb->count : 0; }
bool ringbuf_empty(const ringbuf_t *rb) { return !rb || rb->count == 0; }
bool ringbuf_full(const ringbuf_t *rb) { return rb && rb->count == rb->capacity; }