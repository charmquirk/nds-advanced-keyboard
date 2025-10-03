// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <stdio.h>

#include <nds.h>

#include "keyboardGfx.h"

// Default keyboard map
static const s16 SimpleKbdLower[] =
{
    DVK_FOLD, DVK_FOLD, NOKEY, '1', '1', '2', '2', '3', '3', '4', '4', '5', '5',
    '6', '6', '7', '7', '8', '8', '9', '9', '0', '0', '-', '-', '=', '=',
    DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE,

    DVK_TAB, DVK_TAB, DVK_TAB, DVK_TAB, 'q', 'q', 'w', 'w', 'e', 'e', 'r', 'r',
    't', 't', 'y', 'y', 'u', 'u', 'i', 'i', 'o', 'o', 'p', 'p', '[', '[', ']',
    ']', '\\', '\\', '`', '`',

    DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_CAPS, 'a', 'a', 's', 's', 'd',
    'd', 'f', 'f', 'g', 'g', 'h', 'h', 'j', 'j', 'k', 'k', 'l', 'l', ';', ';',
    '\'', '\'', DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER,

    DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'z', 'z',
    'x', 'x', 'c', 'c', 'v', 'v', 'b', 'b', 'n', 'n', 'm', 'm', ',', ',', '.',
    '.', '/', '/', NOKEY, NOKEY, DVK_UP, DVK_UP, NOKEY, NOKEY,

    DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT,
    DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_MENU,
    DVK_MENU, DVK_MENU, DVK_MENU, DVK_MENU, DVK_LEFT, DVK_LEFT, DVK_DOWN,
    DVK_DOWN, DVK_RIGHT, DVK_RIGHT
};

static const s16 SimpleKbdUpper[] =
{
    DVK_FOLD, DVK_FOLD, NOKEY, '!', '!', '@', '@', '#', '#', '$', '$', '%', '%',
    '^', '^', '&', '&', '*', '*', '(', '(', ')', ')', '_', '_', '+', '+',
    DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE, DVK_BACKSPACE,

    DVK_TAB, DVK_TAB, DVK_TAB, DVK_TAB, 'Q', 'Q', 'W', 'W', 'E', 'E', 'R', 'R',
    'T', 'T', 'Y', 'Y', 'U', 'U', 'I', 'I', 'O', 'O', 'P', 'P', '{', '{', '}',
    '}', '|', '|', '~', '~',

    DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_CAPS, 'A', 'A', 'S', 'S', 'D',
    'D', 'F', 'F', 'G', 'G', 'H', 'H', 'J', 'J', 'K', 'K', 'L', 'L', ':', ':',
    '"', '"', DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER,

    DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'Z', 'Z',
    'X', 'X', 'C', 'C', 'V', 'V', 'B', 'B', 'N', 'N', 'M', 'M', '<', '<', '>',
    '>', '?', '?', NOKEY, NOKEY, DVK_UP, DVK_UP, NOKEY, NOKEY,

    DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT,
    DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_MENU,
    DVK_MENU, DVK_MENU, DVK_MENU, DVK_MENU, DVK_LEFT, DVK_LEFT, DVK_DOWN,
    DVK_DOWN, DVK_RIGHT, DVK_RIGHT
};

static const KeyMap capsLock =
{
    .mapDataPressed = keyboardGfxMap + 32 * 20,
    .mapDataReleased = keyboardGfxMap,
    .keymap = SimpleKbdUpper,
    .width = 32,
    .height = 5
};

static const KeyMap lowerCase =
{
    .mapDataPressed = keyboardGfxMap + 32 * 30,
    .mapDataReleased = keyboardGfxMap + 32 * 10,
    .keymap = SimpleKbdLower,
    .width = 32,
    .height = 5
};

Keyboard kbdDefault =
{
    .scrollSpeed = 3,

    .grid_width = 8,   // Grid width
    .grid_height = 16, // Grid height

    // By setting the initial state to uppercase, and marking the keyboard as
    // shifted, the first character will be uppercase and the next ones will be
    // lowercase, like with modern smartphone keyboards.
    .shifted = true,
    .state = Upper,

    .mappings = {
        &lowerCase, // keymap for lowercase
        &capsLock,  // keymap for caps lock
        0,          // keymap for numeric entry
        0           // keymap for reduced footprint
    },

    .tiles = keyboardGfxTiles,       // graphics tiles
    .tileLen = keyboardGfxTilesLen,  // graphics tiles length
    .palette = keyboardGfxPal,       // palette
    .paletteLen = keyboardGfxPalLen, // size of palette
    .tileOffset = 0,                 // tile offset

    .OnKeyPressed = NULL,            // keypress callback
    .OnKeyReleased = NULL,           // key release callback
};
