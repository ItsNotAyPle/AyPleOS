#ifndef KERNEL_TYPES_H
#define KERNEL_TYPES_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef uint32 size_t;

#define NULL (0)
#define TRUE 1
#define FALSE 0

#define PACKED __attribute__((packed))

#ifndef asm
#define asm __asm__ volatile
#endif

#endif