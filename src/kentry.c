#include "sys/mem.h"
#include "sys/term.h"
#include "sys/abort.h"
#include "cpu/interrupts/idt.h"

extern void kernel_main(void) {
    idt_init();
    term_init();
    term_write("sosig", 5);
    for (;;) {}
}
