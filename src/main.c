#include "includes/screen.h"
#include "includes/io.h"
#include "includes/idt.h"


void kernel_entry() {
  init_idt();
  init_screen();

  outportb(PALETTE_MASK, 0xFF);
  outportb(PALETTE_WRITE, 0);

  for (uint8 i = 0; i < 255; i++) {
      outportb(PALETTE_DATA, (((i >> 5) & 0x7) * (256 / 8)) / 4);
      outportb(PALETTE_DATA, (((i >> 2) & 0x7) * (256 / 8)) / 4);
      outportb(PALETTE_DATA, (((i >> 0) & 0x3) * (256 / 4)) / 4);
  }

  // set color 255 = white
  outportb(PALETTE_DATA, 0x3F);
  outportb(PALETTE_DATA, 0x3F);
  outportb(PALETTE_DATA, 0x3F);

}