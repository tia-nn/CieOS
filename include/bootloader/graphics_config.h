//
// Created by tia on 2020/03/16.
//

#ifndef CIEOS_INCLUDE_BOOTLOADER_GRAPHICS_CONFIG_H
#define CIEOS_INCLUDE_BOOTLOADER_GRAPHICS_CONFIG_H

#include <stdint.h>
#include <bootloader/uefi_base.h>


// from UEFI header

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

// from bootloader

typedef struct GraphicsConfig {
    uint8_t *framebuffer;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION info;
} GraphicsConfig;


#endif //CIEOS_INCLUDE_BOOTLOADER_GRAPHICS_CONFIG_H
