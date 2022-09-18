#include "includes/screen.h"



void kernel_entry() {
  init_screen();
  clear_screen(&vga_buffer, RED);

}