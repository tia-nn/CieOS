//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_INCLUDE_BOOTLOADER_MEMORY_MAP_H
#define CIEOS_INCLUDE_BOOTLOADER_MEMORY_MAP_H


#include <stdint.h>
#include <bootloader/uefi_base.h>


// from UEFI header

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

enum EFI_MEMORY_TYPE {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiMaxMemoryType
};

typedef struct {
    enum EFI_MEMORY_TYPE Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

// from bootloader

typedef struct MemoryMap {
    uint64_t memory_map_size;
    EFI_MEMORY_DESCRIPTOR *memory_map;
    uint64_t map_key;
    uint64_t descriptor_size;
    uint32_t descriptor_version;
} MemoryMap;


#endif //CIEOS_INCLUDE_BOOTLOADER_MEMORY_MAP_H
