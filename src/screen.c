#include "includes/screen.h"
#include "includes/types.h"
#include "includes/memory.h"

static uint8 BUFFER = (volatile uint8*)VGA_ADDRESS;
uint8 SCREEN[SCREEN_W][SCREEN_H];


void clear_screen(uint8 color) {
  memset(&BUFFER, color, SCREEN_SIZE);
}

void init_screen() {

}