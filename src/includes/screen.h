#ifndef KERNEL_SCREEN_H
#define KERNEL_SCREEN_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define SCREEN_W 320
#define SCREEN_H 200
#define SCREEN_SIZE (SCREEN_W * SCREEN_H)

// VGA control ports addresses
// need to do more research into these
#define PALETTE_MASK 0x3C6
#define PALETTE_READ 0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA 0x3C9

// enum vga_color {
//     BLACK,
//     BLUE,
//     GREEN,
//     CYAN,
//     RED,
//     MAGENTA,
//     BROWN,
//     GREY,
//     DARK_GREY,
//     BRIGHT_BLUE,
//     BRIGHT_GREEN,
//     BRIGHT_CYAN,
//     BRIGHT_RED,
//     BRIGHT_MAGENTA,
//     YELLOW,
//     WHITE,
// };

struct rgb {
    uint8 r;
    uint8 g;
    uint8 b;
};

typedef struct rgb Pixel;

static inline Pixel pixel(uint8 r, uint8 g, uint8 b) {
    Pixel p;
    p.r = r;
    p.g = g;
    p.b = b;

    return p;
}


uint8* vga_buffer[SCREEN_SIZE];
uint32 vga_index;

void init_screen();
void clear_screen(uint8 color);


#endif