#include "includes/screen.h"
#include "includes/idt.h"


void kernel_entry() {
  init_idt();
  init_screen();



}