//
// Created by tia on 2020/07/09.
//

#ifndef CIEOS_INCLUDE_FILE_READ_FILESYSTEM_H
#define CIEOS_INCLUDE_FILE_READ_FILESYSTEM_H

#include <stdint.h>

#pragma pack(1)

struct GUID {
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint64_t data4;
};

struct GPTHeader {
    uint8_t signature[8];
    uint32_t revision;
    uint32_t header_size;
    uint32_t CRC32_checksum;
    uint32_t _reserved;
    uint64_t header_lba;
    uint64_t mirror_header_lba;
    uint64_t GPT_entry_first;
    uint64_t GPT_entry_last;
    struct GUID guid;
    uint64_t entry_strat_lba;
    uint32_t entry_count;
    uint32_t entry_size;
    uint32_t CRC32;
    uint8_t _must_be_0[];
};

struct GPTPartitionEntry {
    struct GUID type_GUID;
    struct GUID partition_GUID;
    uint64_t start_lba;
    uint64_t end_lba;
    uint64_t attributes;
    uint16_t name[36];
};

struct FAT32Header {
    uint8_t jmp_boot[3];  // BS 使わない
    uint8_t OEM_name[8];  // BS 使わない
    uint16_t bytes_per_sector;
    uint8_t sector_per_cluster;
    uint16_t header_sector_count;
    uint8_t num_fats;
    uint16_t root_entry_count;
    uint16_t _must_be_0;
    uint8_t media;
    uint16_t _must_be_0_2;
    uint16_t sector_per_track;
    uint16_t num_heads;
    uint32_t hide_sector;
    uint32_t total_sector_32;
    uint32_t sector_per_fat;
    struct {
        unsigned fat_0_active: 1;
        unsigned fat_1_active: 1;
        unsigned fat_2_active: 1;
        unsigned fat_3_active: 1;
        unsigned _reserved: 3;
        unsigned single_active: 1;
        uint8_t _reserved_2;
    } ext_flags;
    uint16_t version;
    uint32_t root_cluster;
    uint16_t fs_info;
    uint16_t backup_boot_sector;
    uint8_t must_be_0[12];
    uint8_t drive_num;  // BS 使わない
    uint8_t must_be_0_2;  // BS 使わない
    uint8_t ex_boot_signature;  // BS 使わない
    uint32_t volume_id;  // BS 使わない
    uint8_t volume_label[11];  // BS 使わない
    uint8_t signature[8];  // BS "FAT32   "
    uint8_t boot_code[420];  // BS 使わない
    uint16_t boot_signature;  // BS 使わない
    uint16_t _[];  // 1セクタが512より大きいとき0で埋める
};

struct DirEntry {
    struct {
        uint8_t name[8];
        uint8_t ext[3];
    } name;
    uint8_t attr;
    uint8_t NT_res;
    uint8_t crt_time_tenth;
    uint16_t crt_time;
    uint16_t crt_date;
    uint16_t lst_acc_data;
    uint16_t first_cluster_high;
    uint16_t write_time;
    uint16_t write_date;
    uint16_t first_cluster_low;
    uint32_t file_size;
};

struct LFNEntry {
    uint8_t ord;
    uint8_t name1[10];
    uint8_t attr;
    uint8_t type;
    uint8_t checksum;
    uint8_t name2[12];
    uint16_t must_be_0;
    uint8_t name3[4];
};

struct Fat32EntryPos {
    uint64_t sector;
    uint64_t offset;
};

#pragma pack()


#endif //CIEOS_INCLUDE_FILE_READ_FILESYSTEM_H
