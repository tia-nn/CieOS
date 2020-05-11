//
// Created by tia on 2020/05/06.
//

#include <memory_allocator/print.h>
#include <bootloader/memory_map.h>
#include <graphics/print.h>
#include <std.h>


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

bool is_usable_memory_type(enum EFI_MEMORY_TYPE type) {
    switch (type) {
        case EfiReservedMemoryType:
            return false;
        case EfiLoaderCode:
            return false;
        case EfiLoaderData:
            return false;
        case EfiBootServicesCode:
            return true;
        case EfiBootServicesData:
            return true;
        case EfiRuntimeServicesCode:
            return false;
        case EfiRuntimeServicesData:
            return false;
        case EfiConventionalMemory:
            return true;
        case EfiUnusableMemory:
            return false;
        case EfiACPIReclaimMemory:
            return false;
        case EfiACPIMemoryNVS:
            return false;
        case EfiMemoryMappedIO:
            return false;
        case EfiMemoryMappedIOPortSpace:
            return false;
        case EfiPalCode:
            return false;
        case EfiPersistentMemory:
            return false;
        case EfiMaxMemoryType:
            return false;
        default:
            return false;
    }
}

void print_memory_map(MemoryMap *mm) {
    EFI_MEMORY_DESCRIPTOR *iter;
    uint64_t i = 0;
    uint64_t x = 0, y = 0;

    uint64_t size = mm->memory_map_size / mm->descriptor_size;

    for (uint64_t i = 0; i < size; i ++) {
        const EFI_MEMORY_DESCRIPTOR * const iter = (uint64_t)mm->memory_map + i * mm->descriptor_size;
        char start[17], end[17], size[17];
        itoa(iter->PhysicalStart, start, 17, 16,
                FILL_ZERO | SET_NULL_TERMINATE);
        itoa(iter->PhysicalStart + iter->NumberOfPages * 0x1000 - 1, end,
                17, 16, FILL_ZERO | SET_NULL_TERMINATE);
        itoa(iter->NumberOfPages * 0x1000, size, 17, 16,
                FILL_ZERO | SET_NULL_TERMINATE);
        const char * type = get_memory_type(iter->Type);
        print("% % % %", start, end, size, type);
    }

}
