#include "mem.h"
#include "defin.h"

typedef struct mem_chunk {
  size_t size;
  enum BOOL freed;
  struct mem_chunk *next;
} mem_chunk;

static mem_chunk mem_chunks_root = {0, FALSE, 0};

void *malloc(size_t size) {
  mem_chunk* start = &mem_chunks_root;
  while (start->next != 0) {
    if (start->freed == FALSE && start->size >= size) {
      return ((char*)start) + sizeof(mem_chunk);
    }
    start = start->next;
  }

  start->next = ((char*)start) + (start->size + sizeof(mem_chunk));
  start = start->next;
  start->size = size;

  return ((char*)start) + sizeof(mem_chunk);
}


void free(void* start) {
  mem_chunk* meta = (mem_chunk*)(start - sizeof(mem_chunk));
  meta->freed = TRUE;
}
