#ifndef KERNEL_IO_H
#define KERNEL_IO_H


// https://github.com/lucianoforks/tetris-os/blob/master/src/util.h
static inline u16 inports(u16 port) {
    u16 r;
    asm("inw %1, %0" : "=a" (r) : "dN" (port));
    return r;
}

static inline void outports(u16 port, u16 data) {
    asm("outw %1, %0" : : "dN" (port), "a" (data));
}

static inline u8 inportb(u16 port) {
    u8 r;
    asm("inb %1, %0" : "=a" (r) : "dN" (port));
    return r;
}

static inline void outportb(u16 port, u8 data) {
    asm("outb %1, %0" : : "dN" (port), "a" (data));
}

#endif