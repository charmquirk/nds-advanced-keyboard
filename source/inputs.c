#include <nds.h>

bool breakMainLoop;
uint16_t keys_down;

void InputUpdate()
{
    scanKeys();
    keys_down = keysDown();

    if (keys_down & KEY_A)
        keyboardShow();

    if (keys_down & KEY_B)
        keyboardHide();

    if (keys_down & KEY_START)
        breakMainLoop = true;
    
}
