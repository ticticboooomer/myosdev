#include "mem.h"
#include "def.h"

typedef struct mem_chunk {
  size_t size;
  Bool freed;
  struct mem_chunk *next;
} mem_chunk;

static mem_chunk mem_chunks_root = {0, FALSE, 0};


void merge_chunks(mem_chunk *start, mem_chunk *end, size_t size) {
  start->next = end->next;
  memset((char *)(start + 1), size, (char)0);
}

Bool can_fit(mem_chunk *head, size_t size) {
  if (head->size >= size && head->freed == TRUE) {
    return TRUE;
  }

  mem_chunk *curr = head->next;
  size_t size_counter = head->size;
  while (curr != 0 && curr->freed) {
    if (curr->size + size_counter < size) {
      size_counter += curr->size;
      continue;
    }
    size_counter += curr->size;
    merge_chunks(head, curr, size_counter);
    return TRUE;
  }
  return FALSE;
}

void init_head(mem_chunk **prev, size_t size) {
  (*prev)->next =
      (mem_chunk *)((char *)*prev) + ((*prev)->size + sizeof(mem_chunk));
  *prev = (*prev)->next;
  (*prev)->size = size;
}

void *malloc(size_t size) {
  mem_chunk *start = &mem_chunks_root;
  while (start->next != 0) {
    if (can_fit(start, size)) {
      return (start) + 1;
    }
    start = start->next;
  }
  init_head(&start, size);
  return (start) + 1;
}

void memset(char *start, size_t size, char ch) {
  for (size_t i = 0; i < size; i++) {
    start[i] = ch;
  }
}

void free(void *start) {
  mem_chunk *meta = (mem_chunk *)(((char *)start) - sizeof(mem_chunk));
  meta->freed = TRUE;
  char *strt = ((char *)start);
  memset(strt, meta->size, (char)0);
}
