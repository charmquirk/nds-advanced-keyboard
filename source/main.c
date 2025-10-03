// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <stdio.h>
#include <nds.h>
#include "ui.h"


int main(int argc, char **argv)
{
    UserInterfaceInit();

    while (1)
    {
        swiWaitForVBlank();

        scanKeys();
        uint16_t keys_down = keysDown();

        if (keys_down & KEY_A)
            keyboardShow();

        if (keys_down & KEY_B)
            keyboardHide();

        if (keys_down & KEY_START)
            break;
        
        UserInterfaceUpdate();
    }

    return 0;
}
