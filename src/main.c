#include "includes/screen.h"

void print_string(const char* str) {
  uint16 i = 0;
  while (str[i]) 
  {
    vga_buffer[vga_index] = vga_entry(str[i], WHITE, BLACK);
    vga_index++;
    i++;
  }
}


void kernel_entry()
{

  init_vga(WHITE, RED);
  print_string("george everett");

}