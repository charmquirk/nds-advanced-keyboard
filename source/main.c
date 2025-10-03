// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <stdio.h>
#include <nds.h>

#include "inputs.h"
#include "ui.h"


int main(int argc, char **argv)
{
    UserInterfaceInit();

    while (1)
    {
        swiWaitForVBlank();

        InputUpdate();
        
        UserInterfaceUpdate();

        if (breakMainLoop)
            break;
    }

    return 0;
}
