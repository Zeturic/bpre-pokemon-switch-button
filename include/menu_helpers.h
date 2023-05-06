#pragma once

#define MENU_L_PRESSED 1
#define MENU_R_PRESSED 2

bool8 MenuHelpers_ShouldWaitForLinkRecv(void);
u8 GetLRKeysPressedAndHeld(void);
