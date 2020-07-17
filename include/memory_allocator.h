//
// Created by tia on 2020/07/17.
//

#ifndef CIEOS_INCLUDE_MEMORY_ALLOCATOR_H
#define CIEOS_INCLUDE_MEMORY_ALLOCATOR_H

#include <bootloader/memory_map.h>
#include "std.h"

void mem_table_init(MemoryMap *mm);
//void print_table();
//void print_memory_map(MemoryMap *mm);
void* page_alloc(uint64_t req_pages);
bool page_free(void *addr);

#endif //CIEOS_INCLUDE_MEMORY_ALLOCATOR_H
