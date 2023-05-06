#pragma once

#include <stddef.h>

struct Main
{
    u8 data1[0x2E];
    u16 newKeys;               // newly pressed keys with L=A remapping
    u16 newAndRepeatedKeys;    // newly pressed keys plus key repeat
    u8 data2[0x40A];
};

typedef void (*MainCallback)(void);

extern struct Main gMain;

_Static_assert(sizeof(struct Main) == 0x43C, "");
_Static_assert(offsetof(struct Main, newKeys) == 0x2E, "");
_Static_assert(offsetof(struct Main, newAndRepeatedKeys) == 0x30, "");
