#ifndef KERNEL_SCREEN_H
#define KERNEL_SCREEN_H

#include "types.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define PIXEL_W 8
#defien PIXEL_H 8
#define SCREEN_W 320
#define SCREEN_H 200
#define SCREEN_SIZE (SCREEN_W * SCREEN_H)

// VGA control ports addresses
// need to do more research into these
#define PALETTE_MASK 0x3C6 // https://wiki.osdev.org/VGA_Hardware#Port_0x3C6
#define PALETTE_READ 0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA 0x3C9

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

struct rgb {
    uint8 r;
    uint8 g;
    uint8 b;
};

typedef struct rgb Pixel;
static uint8 BUFFER = (volatile uint8*)VGA_ADDRESS;
uint8 SCREEN[SCREEN_SIZE];

static inline Pixel pixel(uint8 r, uint8 g, uint8 b) {
    Pixel p;
    p.r = r;
    p.g = g;
    p.b = b;

    return p;
}

// https://stackoverflow.com/questions/53776878/drawing-pixels-in-c-osdev
static inline void plot_pixel(uint8 x, uint8 y, uint8 color) 
{
    uint32 where = x*SCREEN_W + y*SCREEN_H;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
    
    // uint8* location = (uint8*)0xA0000 + 320 * x + y;
    // *location = color;
}


void init_screen();
void clear_screen(uint8 color);

#endif