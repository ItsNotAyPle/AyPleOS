#ifndef KERNEL_MEM_H
#define KERNEL_MEM_H

#include "types.h"

// https://github.com/lucianoforks/tetris-os/blob/master/src/util.h



// sets memory to a value 
static inline void memset(void *dst, uint8 value, size_t n) {
    uint8 *d = dst;

    while (n-- > 0) {
        *d++ = value;
    }
}

static inline void *memcpy(void *dst, const void *src, size_t n) {
    uint8 *d = dst;
    const uint8 *s = src;

    while (n-- > 0) {
        *d++ = *s++;
    }

    return d;
}

static inline void *memmove(void *dst, const void *src, size_t n) {
    // OK since we know that memcpy copies forwards
    if (dst < src) {
        return memcpy(dst, src, n);
    }

    uint8 *d = dst;
    const uint8 *s = src;

    for (size_t i = n; i > 0; i--) {
        d[i - 1] = s[i - 1];
    }

    return dst;
}

#endif