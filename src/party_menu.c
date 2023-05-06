#include "global.h"

#include "main.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "sound.h"

#include "constants/songs.h"

u16 PartyMenuButtonHandler(s8 *slotPtr)
{
    s8 movementDir;

    switch (gMain.newAndRepeatedKeys)
    {
    case DPAD_UP:
        movementDir = MENU_DIR_UP;
        break;
    case DPAD_DOWN:
        movementDir = MENU_DIR_DOWN;
        break;
    case DPAD_LEFT:
        movementDir = MENU_DIR_LEFT;
        break;
    case DPAD_RIGHT:
        movementDir = MENU_DIR_RIGHT;
        break;
    default:
        switch (GetLRKeysPressedAndHeld())
        {
        case MENU_L_PRESSED:
            movementDir = MENU_DIR_UP;
            break;
        case MENU_R_PRESSED:
            movementDir = MENU_DIR_DOWN;
            break;
        default:
            movementDir = 0;
            break;
        }
        break;
    }
    if (JOY_NEW(START_BUTTON))
        return START_BUTTON;
    if (JOY_NEW(SELECT_BUTTON))
        return SELECT_BUTTON;
    if (movementDir)
    {
        UpdateCurrentPartySelection(slotPtr, movementDir);
        return 0;
    }
    if (JOY_NEW(A_BUTTON) && *slotPtr == SLOT_CANCEL)
        return B_BUTTON;
    return JOY_NEW(A_BUTTON | B_BUTTON);
}

void Task_HandleChooseMonInput(u8 taskId)
{
    if (!gPaletteFade.active && MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 *slotPtr = GetCurrentPartySlotPtr();

        switch (PartyMenuButtonHandler(slotPtr))
        {
        case A_BUTTON:
            HandleChooseMonSelection(taskId, slotPtr);
            break;
        case B_BUTTON: // also handles pressing A_BUTTON on Cancel
            HandleChooseMonCancel(taskId, slotPtr);
            break;
        case START_BUTTON:
            if (sPartyMenuInternal->chooseMultiple)
            {
                PlaySE(SE_SELECT);
                MoveCursorToConfirm();
            }
            break;
        case SELECT_BUTTON:
            if (gPartyMenu.action == PARTY_ACTION_CHOOSE_MON
             && gPartyMenu.slotId != SLOT_CANCEL
             && gPartyMenu.menuType == PARTY_MENU_TYPE_FIELD
             && GetMonData(&gPlayerParty[1], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                CursorCB_Switch(taskId);
            }
            break;
        }
    }
}
