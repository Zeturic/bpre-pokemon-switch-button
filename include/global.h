#pragma once

#include "gba/gba.h"

#include "constants/species.h"

#define TEST_BUTTON(field, button) ({(field) & (button);})
#define JOY_NEW(button)      TEST_BUTTON(gMain.newKeys,  button)

#define PACKED __attribute__((packed))
#define NAKED __attribute__((naked))
