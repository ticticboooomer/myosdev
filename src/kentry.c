#include "sys/mem.h"
#include "sys/term.h"

extern void kernel_main(void) {
  term_init();
  char* str1 = malloc(5);
  for (int i = 0; i < 5; i++) {
    str1[i] = 'A';
  }
  term_write(str1, 5);
  char* str2 = malloc(6);
  for (size_t i = 0; i < 6; i++) {
    str2[i] = 'B';
  }
  term_write(str2, 6);
  term_write(str1, 5);
  term_write("123456789012345", 15);

  for (;;){}
}
