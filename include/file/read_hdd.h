//
// Created by tia on 2020/07/04.
//

#ifndef CIEOS_SRC_FILE_READ_HDD_H
#define CIEOS_SRC_FILE_READ_HDD_H

#include <stdint.h>

void read_hdd(void *buf, uint32_t lba, uint8_t sector_count);

#endif //CIEOS_SRC_FILE_READ_HDD_H
