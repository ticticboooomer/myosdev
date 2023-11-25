#include "sys/term.h"
#include "sys/mem.h"

extern void kernel_main(void) {
  term_init();
  char* str1 = kmalloc(5);
  kmemset(str1, 5, 'A');
  term_write(str1, 5);

  char* str2 = kmalloc(6);
  kmemset(str2, 6, 'B');
  term_write(str2, 6);
  kfree(str2);
  term_write(str2, 6);
  term_write(str1, 5);
  term_write(";", 1);
  
  for (;;) {
  }
}
