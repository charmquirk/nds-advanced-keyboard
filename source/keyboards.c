#include <stdio.h>
#include <nds.h>
#include "keyboardGfx.h"

#include "./keyboards/kbd_default.h"
#include "./keyboards/kbd_godot.h"

Keyboard *keyboards[2] =
{
    &kbdDefault, 
    &kbdGodot
};
Keyboard *customKeyboard = NULL;

#define MAX_KEYBOARDS (sizeof(keyboards) / sizeof(keyboards[0]))

int SetKeyboard(int index)
{
    if (index < 0) {
        index = 0;
    }

    int nextIndex = index % (MAX_KEYBOARDS - 1);
    customKeyboard = keyboards[nextIndex];
    return 0;
}