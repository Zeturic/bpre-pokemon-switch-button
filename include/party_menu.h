#pragma once

#include "task.h"

#include "gba/gba.h"

#include "constants/pokemon.h"
#include "constants/party_menu.h"

#define MENU_DIR_DOWN     1
#define MENU_DIR_UP      -1
#define MENU_DIR_RIGHT    2
#define MENU_DIR_LEFT    -2

#define SLOT_CANCEL  (PARTY_SIZE + 1)

struct PartyMenu
{
    MainCallback exitCallback;
    TaskFunc task;
    u8 menuType:4;
    u8 layout:2;
    u8 chooseMonsBattleType:2;
    s8 slotId;
    s8 slotId2;
    u8 action;
    u16 bagItem;
    s16 data[2];
};

struct PartyMenuInternal
{
    TaskFunc task;
    MainCallback exitCallback;
    u32 chooseMultiple:1;
    u32 lastSelectedSlot:3;  // Used to return to same slot when going left/right bewtween columns
    u32 spriteIdConfirmPokeball:7;
    u32 spriteIdCancelPokeball:7;
    u32 messageId:14;
    u8 windowId[3];
    u8 actions[8];
    u8 numActions;
    u16 palBuffer[BG_PLTT_SIZE / sizeof(u16)];
    s16 data[16];
};

extern struct PartyMenu gPartyMenu;
extern struct PartyMenuInternal *sPartyMenuInternal;

void CursorCB_Switch(u8 taskId);
void MoveCursorToConfirm(void);
s8 *GetCurrentPartySlotPtr(void);
void HandleChooseMonSelection(u8 taskId, s8 *slotPtr);
void HandleChooseMonCancel(u8 taskId, s8 *slotPtr);
void UpdateCurrentPartySelection(s8 *slotPtr, s8 movementDir);
