#ifndef KERNEL_IO_H
#define KERNEL_IO_H

#include "types.h"

// https://github.com/lucianoforks/tetris-os/blob/master/src/util.h
static inline uint16 inports(uint16 port) {
    uint16 r;
    asm("inw %1, %0" : "=a" (r) : "dN" (port));
    return r;
}

static inline void outports(uint16 port, uint16 data) {
    asm("outw %1, %0" : : "dN" (port), "a" (data));
}

static inline uint8 inportb(uint16 port) {
    uint8 r;
    asm("inb %1, %0" : "=a" (r) : "dN" (port));
    return r;
}

static inline void outportb(uint16 port, uint8 data) {
    asm("outb %1, %0" : : "dN" (port), "a" (data));
}

#endif