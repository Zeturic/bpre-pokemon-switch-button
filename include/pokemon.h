#pragma once

#include "constants/pokemon.h"

struct Pokemon
{
    u8 data[100];
};

_Static_assert(sizeof(struct Pokemon) == 100, "");

extern struct Pokemon gPlayerParty[];

u32 GetMonData(struct Pokemon *mon, s32 field);
