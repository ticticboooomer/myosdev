#include "sys/mem.h"
#include "sys/term.h"

extern void kernel_main(void) {
  term_init();
  term_write("sosig", 5);
  for (;;){}
}
