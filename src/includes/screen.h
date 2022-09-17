#ifndef KERNEL_SCREEN_H
#define KERNEL_SCREEN_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

uint16* vga_buffer;
uint32 vga_index;

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

// fc - fore color
// bc - back color
uint16 vga_entry(unsigned char ch, uint8 fc, uint8 bc);
void clear_vga_buffer(uint16 **buffer, uint8 fc, uint8 bc);
void init_vga(uint8 fc, uint8 bc);

#endif