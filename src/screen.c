#include "includes/screen.h"
#include "includes/types.h"
#include "includes/memory.h"

static uint8 BUFFER = (volatile uint8*)VGA_ADDRESS;

void clear_screen(uint8 color) {
  memset(&BUFFER, color, SCREEN_SIZE);
  vga_index = 0;
}

void init_screen() {
  vga_index = 0;
}