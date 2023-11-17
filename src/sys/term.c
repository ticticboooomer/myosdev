#include "term.h"

static size_t terminal_row;
static size_t terminal_col;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
  return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color) {
  return (uint16_t)uc | (uint16_t)color;
}

void term_init() {
  terminal_row = 0;
  terminal_col = 0;
  terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
  terminal_buffer =  (uint16_t*)0xB8000;
  for (size_t y = 0; y < VGA_HEIGHT; y++) {
    for (size_t x = 0; x < VGA_WIDTH; x++) {
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = vga_entry(' ', terminal_color);
    }
  }
}

void term_putchar(char c) {
  term_putentryat(c, terminal_color, terminal_col, terminal_row);
  if (++terminal_col == VGA_WIDTH) {
    terminal_col = 0;
    if (++terminal_row == VGA_HEIGHT) {
      terminal_row = 0;
    }
  }
}

void term_write(const char *data, size_t size) {
  for (size_t i = 0; i < size; i++) {
    term_putchar(data[i]);
  }
}

void term_putentryat(char c, uint8_t color, size_t x, size_t y) {
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_entry(c, color);
}

