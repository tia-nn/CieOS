//
// Created by tia on 2020/06/26.
//

#include <paging.h>
#include <stdint.h>


struct PageMapLevel4Entry *PageMapLevel4;//[512];
struct PageDirectoryPointerTableEntry_1GBPage PageDirectoryPointerTable[512];


void init_paging() {
    PageMapLevel4 = (void *)0x3000;

    for (int64_t i = 0; i < 512; i ++) {
        struct PageMapLevel4Entry *pmle = &PageMapLevel4[i];
        pmle->present = 0;
//        pmle->present = 1;
//        pmle->read_write = 1;
//        pmle->user_supervisor = 1;
//        pmle->pageLevel_writeThrough = 0;
//        pmle->pageLevel_cache_disable = 0;
//        pmle->accessed = 0;
//        pmle->_must_be_0 = 0;
//        pmle->phyAddr_of_pageDirectoryPointerTable.addr;
//        pmle->phyAddr_of_pageDirectoryPointerTable._must_be_0 = 0;
//        pmle->xd = 0;

        struct PageDirectoryPointerTableEntry_1GBPage *pdpte = &PageDirectoryPointerTable[i];
        pdpte->present = 0;
//        pdpte->present = 1;
//        pdpte->read_write = 1;
//        pdpte->user_supervisor = 1;
//        pdpte->pageLevel_writeThrough = 0;
//        pdpte->pageLevel_cache_disable = 0;
//        pdpte->accessed = 0;
//        pdpte->dirty = 0;
//        pdpte->must_be_1 = 1;
//        pdpte->global = 1;
//        pdpte->pat = 0;
//        pdpte->phyAddr_of_1GB_page.addr;
//        pdpte->phyAddr_of_1GB_page._must_be_0 = 0;
//        pdpte->protect_key = 0;
//        pdpte->xd = 0;
    }

//    struct PageMapLevel4Entry *pmle = &PageMapLevel4[0];
//    pmle->present = 1;
//    pmle->read_write = 1;
//    pmle->user_supervisor = 1;
//    pmle->pageLevel_writeThrough = 0;
//    pmle->pageLevel_cache_disable = 0;
//    pmle->accessed = 0;
//    pmle->_must_be_0 = 0;
//    pmle->phyAddr_of_pageDirectoryPointerTable.addr = 0;
//    pmle->phyAddr_of_pageDirectoryPointerTable._must_be_0 = 0;
//    pmle->xd = 0;
//
//    struct PageDirectoryPointerTableEntry_1GBPage *pdpte = &PageDirectoryPointerTable[0];
//    pdpte->present = 1;
//    pdpte->read_write = 1;
//    pdpte->user_supervisor = 1;
//    pdpte->pageLevel_writeThrough = 0;
//    pdpte->pageLevel_cache_disable = 0;
//    pdpte->accessed = 0;
//    pdpte->dirty = 0;
//    pdpte->must_be_1 = 1;
//    pdpte->global = 1;
//    pdpte->pat = 0;
//    pdpte->phyAddr_of_1GB_page.addr = 0;
//    pdpte->phyAddr_of_1GB_page._must_be_0 = 0;
//    pdpte->protect_key = 0;
//    pdpte->xd = 0;
}

