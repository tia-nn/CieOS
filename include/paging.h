//
// Created by tia on 2020/06/26.
//

#ifndef CIEOS_INCLUDE_PAGING_H
#define CIEOS_INCLUDE_PAGING_H


#define MAXPHYADDR 40

#pragma pack(1)

struct PageMapLevel4Entry {
    unsigned present: 1;
    unsigned read_write: 1;
    unsigned user_supervisor: 1;
    unsigned pageLevel_writeThrough: 1;
    unsigned pageLevel_cache_disable: 1;
    unsigned accessed: 1;
    unsigned _ignore: 1;
    unsigned _must_be_0: 1;
    unsigned ignore: 4;
    struct {
        unsigned addr: 28;
        unsigned _must_be_0: 12;
    } phyAddr_of_pageDirectoryPointerTable;
    unsigned _ignore_2: 11;
    unsigned xd: 1;
};

struct PageDirectoryPointerTableEntry_1GBPage {
    unsigned present: 1;
    unsigned read_write: 1;
    unsigned user_supervisor: 1;
    unsigned pageLevel_writeThrough: 1;
    unsigned pageLevel_cache_disable: 1;
    unsigned accessed: 1;
    unsigned dirty: 1;
    unsigned must_be_1: 1;
    unsigned global: 1;
    unsigned _ignore: 3;
    unsigned pat: 1;
    unsigned _ignore_2: 17;
    struct {
        unsigned addr: 10;
        unsigned _must_be_0: 12;
    } phyAddr_of_1GB_page;
    unsigned _ignore_3: 7;
    unsigned protect_key: 4;
    unsigned xd: 1;
};

//extern struct PageMapLevel4Entry PageMapLevel4[512];
extern struct PageMapLevel4Entry *PageMapLevel4;//[512];

void init_paging();

#pragma pack()

#endif //CIEOS_INCLUDE_PAGING_H
