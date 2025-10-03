#include <nds.h>

#include "main.h"
#include "inputs.h"

uint16_t keys_down;


void InputInit()
{
    
}

void InputUpdate()
{
    scanKeys();
    keys_down = keysDown();

    if (keys_down & KEY_A)
        keyboardShow();

    if (keys_down & KEY_B)
        keyboardHide();

    if (keys_down & KEY_START)
        isLooping = false;
}

void InputCleanup()
{
    
}
