#include "sys/term.h"
#include "sys/mem.h"

extern void kernel_main(void) {
  term_init();
  char* str1 = malloc(5);
  memset(str1, 5, 'A');
  term_write(str1, 5);

  char* str2 = malloc(6);
  memset(str2, 6, 'B');
  term_write(str2, 6);
  free(str2);
  term_write(str2, 6);
  term_write(str1, 5);
  term_write(";", 1);
  
  for (;;) {
  }
}
