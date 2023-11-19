#include "sys/mem.h"
#include "sys/term.h"

extern void kernel_main(void) {
  term_init();
  char* str = malloc(15 * sizeof(char));
  for (int i = 0; i < 15; i++) {
    str[i] = 'g';
  }
  term_write("123456789012345", 15);
  for (;;){}
}
