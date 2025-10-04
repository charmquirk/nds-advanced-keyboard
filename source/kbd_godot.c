#include <nds.h>
#include "kbd_godot.h"
#include "kbdGfxGodot.h"


#define KEYS_IN_ROW 12
#define ROWS_OF_KEYS 32


static const s16 KbdLower[] =
{
    // Margin
    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY,

    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY, 

    // First Row
    NOKEY, DVK_FOLD, DVK_FOLD, '1', '1', '2', '2', '3', '3', '4', '4', '5', '5', '6', '6',
    '7',
    
    '7', '8', '8', '9', '9', '0', '0', '-', '-', '=', '=', DVK_BACKSPACE, DVK_BACKSPACE,
    DVK_BACKSPACE, DVK_BACKSPACE, NOKEY,

    NOKEY, DVK_FOLD, DVK_FOLD, '1', '1', '2', '2', '3', '3', '4', '4', '5', '5', '6', '6',
    '7',
    
    '7', '8', '8', '9', '9', '0', '0', '-', '-', '=', '=', DVK_BACKSPACE, DVK_BACKSPACE,
    DVK_BACKSPACE, DVK_BACKSPACE, NOKEY,

    // Second Row
    NOKEY, DVK_TAB, DVK_TAB, DVK_TAB, 'q', 'q', 'w', 'w', 'e', 'e', 'r', 'r', 't', 't', 'y', 'y',

    'u', 'u', 'i', 'i', 'o', 'o', 'p', 'p', '[', '[', ']', ']', NOKEY, NOKEY, NOKEY, NOKEY,

    NOKEY, DVK_TAB, DVK_TAB, DVK_TAB, 'q', 'q', 'w', 'w', 'e', 'e', 'r', 'r', 't', 't', 'y', 'y',

    'u', 'u', 'i', 'i', 'o', 'o', 'p', 'p', '[', '[', ']', ']', NOKEY, NOKEY, NOKEY, NOKEY,

    //Third Row
    NOKEY, 'a', 'a', 's', 's', 'd', 'd', 'f', 'f', 'g', 'g', 'h', 'h', 'j', 'j', 'k',

    'k', 'l', 'l', ';', ';', '\'', '\'', '\\', '\\', '`', '`', NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,

    NOKEY, 'a', 'a', 's', 's', 'd', 'd', 'f', 'f', 'g', 'g', 'h', 'h', 'j', 'j', 'k',

    'k', 'l', 'l', ';', ';', '\'', '\'', '\\', '\\', '`', '`', NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,

    //Fourth Row
    NOKEY, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'z', 'z', 'x', 'x', 'c', 'c', 'v', 'v', 'b', 'b', 'n',
    'n',
    
    'm', 'm', ',', ',', '.', '.', '/', '/', DVK_CAPS, DVK_CAPS, DVK_CAPS, NOKEY, DVK_UP, DVK_UP, NOKEY,
    NOKEY,

    NOKEY, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'z', 'z', 'x', 'x', 'c', 'c', 'v', 'v', 'b', 'b', 'n',
    'n',
    
    'm', 'm', ',', ',', '.', '.', '/', '/', DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_LEFT, NOKEY, NOKEY,
    DVK_RIGHT, NOKEY,

    //Fifth Row
    NOKEY, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,

    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_MENU, DVK_MENU,
    DVK_MENU, DVK_LEFT, NOKEY, NOKEY, DVK_RIGHT, NOKEY,

    NOKEY, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,

    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_MENU, DVK_MENU,
    DVK_MENU, NOKEY, DVK_DOWN, DVK_DOWN, NOKEY, NOKEY,

    // Margin
    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY,

    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY, 
};

static const s16 KbdUpper[] =
{
    // Margin
    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY,

    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY,

    // First Row
    NOKEY, DVK_FOLD, DVK_FOLD, '!', '!', '@', '@', '#', '#', '$', '$', '%', '%', '^', '^',
    '&',
    
    '&', '*', '*', '(', '(', ')', ')', '_', '_', '+', '+', DVK_BACKSPACE, DVK_BACKSPACE,
    DVK_BACKSPACE, DVK_BACKSPACE, NOKEY,

    NOKEY, DVK_FOLD, DVK_FOLD, '!', '!', '@', '@', '#', '#', '$', '$', '%', '%', '^', '^',
    '&',
    
    '&', '*', '*', '(', '(', ')', ')', '_', '_', '+', '+', DVK_BACKSPACE, DVK_BACKSPACE,
    DVK_BACKSPACE, DVK_BACKSPACE, NOKEY,

    // Second Row
    NOKEY, DVK_TAB, DVK_TAB, DVK_TAB, 'Q', 'Q', 'W', 'W', 'E', 'E', 'R', 'R', 'T', 'T', 'Y', 'Y',

    'U', 'U', 'I', 'I', 'O', 'O', 'P', 'P', '{', '{', '}', '}', NOKEY, NOKEY, NOKEY, NOKEY,

    NOKEY, DVK_TAB, DVK_TAB, DVK_TAB, 'Q', 'Q', 'W', 'W', 'E', 'E', 'R', 'R', 'T', 'T', 'Y', 'Y',

    'U', 'U', 'I', 'I', 'O', 'O', 'P', 'P', '{', '{', '}', '}', NOKEY, NOKEY, NOKEY, NOKEY,

    //Third Row
    NOKEY, 'A', 'A', 'S', 'S', 'D', 'D', 'F', 'F', 'G', 'G', 'H', 'H', 'J', 'J', 'K',

    'K', 'L', 'L', ':', ':', '"', '"', '|', '|', '~', '~', NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,

    NOKEY, 'A', 'A', 'S', 'S', 'D', 'D', 'F', 'F', 'G', 'G', 'H', 'H', 'J', 'J', 'K',

    'K', 'L', 'L', ':', ':', '"', '"', '|', '|', '~', '~', NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,

    //Fourth Row
    NOKEY, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'Z', 'Z', 'X', 'X', 'C', 'C', 'V', 'V', 'B', 'B', 'N',
    'N',
    
    'M', 'M', '<', '<', '>', '>', '?', '?', DVK_CAPS, DVK_CAPS, DVK_CAPS, NOKEY, DVK_UP, DVK_UP, NOKEY,
    NOKEY,

    NOKEY, DVK_SHIFT, DVK_SHIFT, DVK_SHIFT, 'Z', 'Z', 'X', 'X', 'C', 'C', 'V', 'V', 'B', 'B', 'N',
    'N',
    
    'M', 'M', '<', '<', '>', '>', '?', '?', DVK_CAPS, DVK_CAPS, DVK_CAPS, DVK_LEFT, NOKEY, NOKEY,
    DVK_RIGHT, NOKEY,
    
    //Fifth Row
    NOKEY, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,

    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_MENU, DVK_MENU,
    DVK_MENU, DVK_LEFT, NOKEY, NOKEY, DVK_RIGHT, NOKEY,

    NOKEY, DVK_CTRL, DVK_CTRL, DVK_CTRL, DVK_ALT, DVK_ALT, DVK_ALT, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,
    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_SPACE,

    DVK_SPACE, DVK_SPACE, DVK_SPACE, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_ENTER, DVK_MENU, DVK_MENU,
    DVK_MENU, NOKEY, DVK_DOWN, DVK_DOWN, NOKEY, NOKEY,

    // Margin
    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY,

    NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY, NOKEY,
    NOKEY, NOKEY, 
};

static const KeyMap capsOn =
{
    .mapDataPressed = kbdGfxGodotMap + ROWS_OF_KEYS * KEYS_IN_ROW * 2,
    .mapDataReleased = kbdGfxGodotMap,
    .keymap = KbdUpper,
    .width = ROWS_OF_KEYS,
    .height = KEYS_IN_ROW
};

static const KeyMap capsOff =
{
    .mapDataPressed = kbdGfxGodotMap + ROWS_OF_KEYS * KEYS_IN_ROW * 3,
    .mapDataReleased = kbdGfxGodotMap + ROWS_OF_KEYS * KEYS_IN_ROW,
    .keymap = KbdLower,
    .width = ROWS_OF_KEYS,
    .height = KEYS_IN_ROW
};

const Keyboard kbdGodot =
{
    .scrollSpeed = 6,

    .grid_width = 8,   // Grid width
    .grid_height = 8, // Grid height

    // By setting the initial state to uppercase, and marking the keyboard as
    // shifted, the first character will be uppercase and the next ones will be
    // lowercase, like with modern smartphone keyboards.
    .shifted = false,
    .state = Lower,

    .mappings = {
        &capsOff,   // keymap for lowercase
        &capsOn,    // keymap for uppercase
        0,          // keymap for numeric entry
        0           // keymap for reduced footprint
    },

    .tiles = kbdGfxGodotTiles,       // graphics tiles
    .tileLen = kbdGfxGodotTilesLen,  // graphics tiles length
    .palette = kbdGfxGodotPal,       // palette
    .paletteLen = kbdGfxGodotPalLen, // size of palette
    .tileOffset = 0,                 // tile offset

    .OnKeyPressed = NULL,            // keypress callback
    .OnKeyReleased = NULL,           // key release callback
};