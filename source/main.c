// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <nds.h>

#include "main.h"
#include "inputs.h"
#include "ui.h"


bool isLooping;


int main(int argc, char **argv)
{
    InputInit();

    UserInterfaceInit();

    isLooping = true;

    while (isLooping)
    {
        swiWaitForVBlank();

        InputUpdate();
        
        UserInterfaceUpdate();
    }

    InputCleanup();

    UserInterfaceCleanup();

    return 0;
}
