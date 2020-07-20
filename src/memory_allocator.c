//
// Created by tia on 2020/07/17.
//

#include "memory_allocator.h"
#include <std.h>
#include <bootloader/memory_map.h>
#include <graphics/print.h>

#define MEMORYTABLESIZE 4000

struct MemoryTableRecord {
    uint64_t addr;
    uint64_t page_count;
    bool using;
    bool exist;
};

struct MemoryTableRecord MEMORY_TABLE[MEMORYTABLESIZE];

bool is_usable_memory_type(enum EFI_MEMORY_TYPE type) {
    switch (type) {
        case EfiReservedMemoryType:
        case EfiLoaderCode:
        case EfiLoaderData:
        case EfiRuntimeServicesCode:
        case EfiRuntimeServicesData:
        case EfiUnusableMemory:
        case EfiACPIReclaimMemory:
        case EfiACPIMemoryNVS:
        case EfiMemoryMappedIO:
        case EfiMemoryMappedIOPortSpace:
        case EfiPalCode:
        case EfiPersistentMemory:
        case EfiMaxMemoryType:
            return false;
        case EfiBootServicesCode:
        case EfiBootServicesData:
        case EfiConventionalMemory:
            return true;
        default:
            return false;
    }
}

void push_table(struct MemoryTableRecord new_record) {
    uint64_t push_index = 0;
    bool found = false;
    for (uint64_t i = 0; i < MEMORYTABLESIZE; i ++) {
        struct MemoryTableRecord *record = &MEMORY_TABLE[i];
        if (record->exist) {
            if (!record->using) {
                if (record->addr + record->page_count * 0x1000 == new_record.addr) {
                    record->page_count += new_record.page_count;
                    return;
                } else if (new_record.addr + new_record.page_count * 0x1000 == record->addr) {
                    record->addr = new_record.addr;
                    record->page_count += new_record.page_count;
                    return;
                }
            }
        } else if (!found) {
            found = true;
            push_index = i;
        }
    }
    MEMORY_TABLE[push_index] = new_record;
}

void mem_table_init(MemoryMap *mm) {
    uint64_t size = mm->memory_map_size / mm->descriptor_size;
    for (uint64_t i = 0; i < size; i ++) {
        const EFI_MEMORY_DESCRIPTOR * const iter = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mm->memory_map + i * mm->descriptor_size);
        if (is_usable_memory_type(iter->Type)) {
            struct MemoryTableRecord record;
            if (iter->PhysicalStart == 0) {
                if (iter->NumberOfPages == 1) continue;
                else {
                    record.addr = 0x1000;
                    record.page_count = iter->NumberOfPages - 1;
                }
            } else {
                record.addr = iter->PhysicalStart;
                record.page_count = iter->NumberOfPages;
            }
            record.using = false;
            record.exist = true;
            push_table(record);
        }
    }
}

void print_table() {
    char buf1[17], buf2[20], buf3[17];
    for (uint64_t i = 0; i < MEMORYTABLESIZE; i ++) {
        struct MemoryTableRecord record = MEMORY_TABLE[i];
        if (record.exist) {
            itoa(record.addr, buf1, 17, 16, SET_NULL_TERMINATE | FILL_ZERO);
            itoa(record.page_count, buf2, 20, 10, SET_NULL_TERMINATE);
            print("addr: %, size: %, %", buf1, buf2, bool2shortstraddr(record.using));
        }
    }
}

void* page_alloc(uint64_t req_pages) {
    for (uint64_t i = 0; i < MEMORYTABLESIZE; i ++) {
        struct MemoryTableRecord *record = &MEMORY_TABLE[i];
        if (record->exist && !record->using && record->page_count >= req_pages) {
            struct MemoryTableRecord new_record;
            record->using = true;
            new_record.page_count = record->page_count - req_pages;
            record->page_count = req_pages;
            new_record.addr = record->addr + req_pages * 0x1000;
            new_record.exist = true;
            new_record.using = false;
            if (new_record.page_count) {
                push_table(new_record);
            }
            return (void *)record->addr;
        }
    }
    return null;
}

bool page_free(void *addr) {
    struct MemoryTableRecord *old_record;
    bool found = false;
    for (uint64_t i = 0; i < MEMORYTABLESIZE; i ++) {
        if (MEMORY_TABLE[i].addr == (uint64_t)addr) {
            old_record = &MEMORY_TABLE[i];
            found = true;
            break;
        }
    }
    if (!found) {
        return false;
    }


    for (uint64_t i = 0; i < MEMORYTABLESIZE; i ++) {
        struct MemoryTableRecord *record = &MEMORY_TABLE[i];
        if (record->exist && !record->using) {
            if (record->addr + record->page_count * 0x1000 == old_record->addr) {
                record->page_count += old_record->page_count;
                old_record->exist = false;
                return true;
            } else if (old_record->addr + old_record->page_count * 0x1000 == record->addr) {
                record->addr = old_record->addr;
                record->page_count += old_record->page_count;
                old_record->exist = false;
                return true;
            }
        }
    }
    old_record->using = false;
    return true;
}


// ------


const char *get_memory_type(enum EFI_MEMORY_TYPE type) {
    switch (type) {
        case EfiReservedMemoryType:
            return "EfiReservedMemoryType";
        case EfiLoaderCode:
            return "EfiLoaderCode";
        case EfiLoaderData:
            return "EfiLoaderData";
        case EfiBootServicesCode:
            return "EfiBootServicesCode";
        case EfiBootServicesData:
            return "EfiBootServicesData";
        case EfiRuntimeServicesCode:
            return "EfiRuntimeServicesCode";
        case EfiRuntimeServicesData:
            return "EfiRuntimeServicesData";
        case EfiConventionalMemory:
            return "EfiConventionalMemory";
        case EfiUnusableMemory:
            return "EfiUnusableMemory";
        case EfiACPIReclaimMemory:
            return "EfiACPIReclaimMemory";
        case EfiACPIMemoryNVS:
            return "EfiACPIMemoryNVS";
        case EfiMemoryMappedIO:
            return "EfiMemoryMappedIO";
        case EfiMemoryMappedIOPortSpace:
            return "EfiMemoryMappedIOPortSpace";
        case EfiPalCode:
            return "EfiPalCode";
        case EfiPersistentMemory:
            return "EfiPersistentMemory";
        case EfiMaxMemoryType:
            return "EfiMaxMemoryType";
        default:
            return "InvalidMemoryType";
    }
}

void print_memory_map(MemoryMap *mm) {
    EFI_MEMORY_DESCRIPTOR *iter;
    uint64_t i = 0;
    uint64_t x = 0, y = 0;

    uint64_t size = mm->memory_map_size / mm->descriptor_size;

    for (uint64_t i = 0; i < 30; i ++) {
        const EFI_MEMORY_DESCRIPTOR * const iter = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)mm->memory_map + i * mm->descriptor_size);
        char start[17], end[17], size[17];
        char *status;
        itoa(iter->PhysicalStart, start, 17, 16,
             FILL_ZERO | SET_NULL_TERMINATE);
        itoa(iter->PhysicalStart + iter->NumberOfPages * 0x1000 - 1, end,
             17, 16, FILL_ZERO | SET_NULL_TERMINATE);
        itoa(iter->NumberOfPages, size, 17, 10,
             SET_NULL_TERMINATE);
        if (is_usable_memory_type(iter->Type)) {
            status = "o";
            print("%-% % %", start, end, size, status);
        } else {
            status = "x";
        }
    }

}

