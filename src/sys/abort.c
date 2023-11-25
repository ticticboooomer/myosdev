#include "abort.h"

void abort() {
  asm volatile("hlt");

}
