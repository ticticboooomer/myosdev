#include "mem.h"

typedef struct mem_chunk {
  size_t size;
  enum BOOL freed;
  struct mem_chunk *next;
} mem_chunk;

static mem_chunk mem_chunks_root = {0, FALSE, 0};

mem_chunk* alloc_chunk_header(size_t size) {
  int sz = size;
  mem_chunk* header = (mem_chunk*)((char*)&sz);
  header->size = size;
  header->next = 0;
  return header;
}

void *malloc(size_t size) {
  mem_chunk* block = mem_chunks_root.next;
  if (block == 0) {
    block = (mem_chunk*)(void*)&(mem_chunks_root.next);
  }
  mem_chunk** head = block->next;
  while (block != 0) {
    if (block->freed && block->size >= size) {
      return block + sizeof(mem_chunk);
    }
    head += sizeof(mem_chunk) + block->size;
    block = *head;
  }
  
  return block + sizeof(mem_chunk);
}

void free(void* start) {
  mem_chunk* meta = (mem_chunk*)(((char*)start) - sizeof(mem_chunk));
  meta->freed = TRUE;
  // TODO: defrag
}
