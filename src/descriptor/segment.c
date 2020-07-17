//
// Created by tia on 2020/05/06.
//

#include <descriptor/segment.h>
#include <descriptor/table.h>
#include <std.h>

struct SegmentDescriptor GDT[GDT_LEN];


void GDT_set_null(uint64_t index) {
    GDT[index].bit_00_63 = 0;
}

void set_data_segment_descriptor(struct SegmentDescriptor *dist, uint32_t base, uint32_t limit,
        bool accessed, bool writeable, bool expansion_direction,
        uint8_t dpl, bool present, bool available, bool big, bool granularity) {

    struct DataSegmentDescriptor *dsd = (struct DataSegmentDescriptor *)dist;

    dsd->_reserved_0 = 0;
    dsd->_reserved_1 = 1;
    dsd->_reserved2_0 = 0;

    if (accessed) dsd->accessed = 1; else dsd->accessed = 0;
    if (writeable) dsd->writeable = 1; else dsd->writeable = 0;
    if (expansion_direction) dsd->expansion_direction = 1; else dsd->expansion_direction = 0;
    dsd->dpl = dpl & 0b00000011;
    if (present) dsd->present = 1; else dsd->present = 0;
    if (available) dsd->available = 1; else dsd->available = 0;
    if (big) dsd->big = 1; else dsd->big = 0;
    if (granularity) dsd->granularity = 1; else dsd->granularity = 0;

    dsd->base_00_15 = base & 0x0000ffff;
    dsd->base_16_23 = (base >> 16) & 0x000000ff;
    dsd->base_24_31 = base >> 24;

    dsd->limit_00_15 = limit & 0x0000ffff;
    dsd->limit_16_19 = (limit >> 16) & 0x0000000f;
}

void set_code_segment_descriptor_64(struct SegmentDescriptor *dist, bool accessed, bool readable, bool conforming,
        uint8_t dpl, bool present, bool available, bool long_flag, bool default_, bool granularity) {

    struct CodeSegmentDescriptor64 *csd = (struct CodeSegmentDescriptor64 *) dist;

    csd->_reserved_1 = 1;
    csd->_reserved2_1 = 1;

    if (accessed) csd->accessed = 1; else csd->accessed = 0;
    if (readable) csd->readable = 1; else csd->readable = 0;
    if (conforming) csd->conforming = 1; else csd->conforming = 0;

    csd->dpl = dpl & 0b00000011;

    if (present) csd->present = 1; else csd->present = 0;
    if (available) csd->available = 1; else csd->available = 0;
    if (long_flag) csd->long_flag = 1; else csd->long_flag = 0;
    if (default_) csd->default_ = 1; else csd->default_ = 0;
    if (granularity) csd->granularity = 1; else csd->granularity = 0;
}

void GDT_init() {
    GDT_set_null(0);
    set_code_segment_descriptor_64(&GDT[1], true, true, false, 0, true, true, true, false, true);
    set_data_segment_descriptor(&GDT[2], 0, 0xffffffff, true, true, false, 0, true, true, true, true);
    set_code_segment_descriptor_64(&GDT[3], true, true, false, 0, true, true, true, false, true);
    set_data_segment_descriptor(&GDT[4], 0, 0xffffffff, true, true, false, 0, true, true, true, true);
    set_code_segment_descriptor_64(&GDT[5], true, true, false, 0, true, true, true, false, true);
    set_data_segment_descriptor(&GDT[6], 0, 0xffffffff, true, true, false, 0, true, true, true, true);
    set_code_segment_descriptor_64(&GDT[7], true, true, false, 0, true, true, true, false, true);
    set_data_segment_descriptor(&GDT[8], 0, 0xffffffff, true, true, false, 0, true, true, true, true);
}

//__attribute__((always_inline)) inline void load_global_descriptor_table() {
//    struct DescriptorTableRegister gdtr = {GDT_LIMIT, (uint64_t)GDT};
//
//    __asm__ volatile (
//    "lea rax, %0 \n"
//    "lgdt [rax]"
//    : : "m"(gdtr));
//}
