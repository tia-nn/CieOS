//
// Created by tia on 2020/09/16.
//

#ifndef CIEOS_SRC_BOOTLOADER_H
#define CIEOS_SRC_BOOTLOADER_H

#include <stdint.h>

typedef uint32_t UINT32;
typedef uint64_t UINT64;

// from edk2 UEFI.h

typedef struct {
    UINT32 RedMask;
    UINT32 GreenMask;
    UINT32 BlueMask;
    UINT32 ReservedMask;
} EFI_PIXEL_BITMASK;

typedef enum {
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct {
    UINT32 Version;
    UINT32 HorizontalResolution;
    UINT32 VerticalResolution;
    EFI_GRAPHICS_PIXEL_FORMAT PixelFormat;
    EFI_PIXEL_BITMASK PixelInformation;
    UINT32 PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

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

typedef struct GraphicsConfig {
    uint8_t *framebuffer;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION info;
} GraphicsConfig;

typedef struct MemoryMap {
    uint64_t memory_map_size;
    EFI_MEMORY_DESCRIPTOR *memory_map;
    uint64_t map_key;
    uint64_t descriptor_size;
    uint32_t descriptor_version;
} MemoryMap;

#endif //CIEOS_SRC_BOOTLOADER_H
