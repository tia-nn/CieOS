//
// Created by tia on 2020/06/28.
//

#ifndef CIEOS_INCLUDE_CONTROL_REGISTERS_H
#define CIEOS_INCLUDE_CONTROL_REGISTERS_H

#pragma pack(1)

struct CR0 {
    unsigned protected_mode_enable: 1;
    unsigned monitor_coProcessor: 1;
    unsigned emulation: 1;
    unsigned task_switched: 1;
    unsigned extension_type: 1;
    unsigned numeric_error: 1;
    unsigned _reserved: 10;
    unsigned write_protect: 1;
    unsigned _reserved_2: 1;
    unsigned alignment_mask: 1;
    unsigned _reserved_3: 10;
    unsigned not_write_throw: 1;
    unsigned cache_disable: 1;
    unsigned paging: 1;
    uint32_t _reserved_4;
};

struct CR3 {
//    union {
//        struct {
//            unsigned _reserved: 3;
//            unsigned pageLevel_write_throw: 1;
//            unsigned pageLevel_cache_disable: 1;
//            unsigned _reserved_2: 7;
//        } PAT;
        unsigned PCID: 12;
//    };
    uint64_t PML4_addr: 52;
};

//struct CR4 {
//    unsigned virtual_8086Mode_extensions: 1;
//    unsigned protected_mode_virtual_interrupts: 1;
//    unsigned
//};

#pragma pack()

#endif //CIEOS_INCLUDE_CONTROL_REGISTERS_H
