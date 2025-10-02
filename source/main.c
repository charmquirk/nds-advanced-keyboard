// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <stdio.h>

#include <nds.h>

#include "keyboardGfx.h"

static const int keyDimensions = 16;
static const int keysInRow = 12;
static const int rowsOfKeys = 5;

// Default keyboard map
// Needs DVK_FOLD, DVK_MENU, DVK_LEFT, DVK_DOWN, DVK_RIGHT, DVK_UP
static const s16 KbdLower[] =
{
    '1', '1', '2', '2', '3', '3', '4', '4', '5', '5', '6', '6',
    '7', '7', '8', '8', '9', '9', '0', '0', '-', '-', '=', '=',

    'q', 'q', 'w', 'w', 'e', 'e', 'r', 'r', 't', 't', 'y', 'y',
    'u', 'u', 'i', 'i', 'o', 'o', 'p', 'p', '[', '[', ']', ']',

    'a', 'a', 's', 's', 'd', 'd', 'f', 'f', 'g', 'g', 'h', 'h',
    'j', 'j', 'k', 'k', 'l', 'l', ';', ';', '\'', '\'', '\\', '\\', 

    NOKEY, 'z', 'z', 'x', 'x', 'c', 'c', 'v', 'v', 'b', 'b', 'n',
    'n', 'm', 'm', ',', ',', '.', '.', '/', '/', '`', '`', NOKEY,

    DVK_TAB, DVK_TAB, DVK_ENTER,DVK_ENTER, DVK_CAPS, DVK_CAPS, DVK_ALT, DVK_ALT,
    DVK_CTRL, DVK_CTRL, DVK_SPACE, DVK_SPACE, DVK_BACKSPACE, DVK_BACKSPACE, NOKEY, NOKEY,
};

static const s16 KbdUpper[] =
{
    '!', '!', '@', '@', '#', '#', '$', '$', '%', '%', '^', '^',
    '&', '&', '*', '*', '(', '(', ')', ')', '_', '_', '+', '+',

    'Q', 'Q', 'W', 'W', 'E', 'E', 'R', 'R', 'T', 'T', 'Y', 'Y',
    'U', 'U', 'I', 'I', 'O', 'O', 'P', 'P', '{', '{', '}', '}',

    'A', 'A', 'S', 'S', 'D', 'D', 'F', 'F', 'G', 'G', 'H', 'H',
    'J', 'J', 'K', 'K', 'L', 'L', ':', ':', '"', '"', '|', '|',

    NOKEY, 'Z', 'Z', 'X', 'X', 'C', 'C', 'V', 'V', 'B', 'B', 'N',
    'N', 'M', 'M', '<', '<', '>', '>', '?', '?', '~', '~', NOKEY,

    DVK_TAB, DVK_TAB, DVK_ENTER,DVK_ENTER, DVK_CAPS, DVK_CAPS, DVK_ALT, DVK_ALT,
    DVK_CTRL, DVK_CTRL, DVK_SPACE, DVK_SPACE, DVK_BACKSPACE, DVK_BACKSPACE, NOKEY, NOKEY,
};

static const KeyMap capsOn =
{
    .mapDataPressed = keyboardGfxMap,
    .mapDataReleased = keyboardGfxMap,
    .keymap = KbdUpper,
    .width = keysInRow * 2,
    .height = rowsOfKeys
};

static const KeyMap capsOff =
{
    .mapDataPressed = keyboardGfxMap,
    .mapDataReleased = keyboardGfxMap,
    .keymap = KbdLower,
    .width = keysInRow * 2,
    .height = rowsOfKeys
};

static const Keyboard customKeyboard =
{
    .scrollSpeed = 4,

    .grid_width = keyDimensions/2,   // Grid width
    .grid_height = keyDimensions, // Grid height

    // By setting the initial state to uppercase, and marking the keyboard as
    // shifted, the first character will be uppercase and the next ones will be
    // lowercase, like with modern smartphone keyboards.
    .shifted = true,
    .state = Upper,

    .mappings = {
        &capsOff,   // keymap for lowercase
        &capsOn,    // keymap for uppercase
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

    .offset_x = -32,
    .offset_y = -32,
};

int main(int argc, char **argv)
{
    consoleDemoInit();

    // Load keyboard in the main screen, for a change
    videoSetMode(MODE_0_2D);

    // Move the main screen to the touch screen so that we can actually use the
    // keyboard.
    lcdMainOnBottom();

    // Initialize the keyboard and load its graphics
    keyboardInit(&customKeyboard,
                 3,                // Background layer to use
                 BgType_Text4bpp,  // 16 color palette format
                 BgSize_T_256x512, // Background size
                 20,               // Map base
                 0,                // Tile base
                 true,             // Display it on the main screen
                 true);            // Load graphics to VRAM

    char string[50];
    string[0] = '\0';
    int string_cursor = 0;

    while (1)
    {
        swiWaitForVBlank();

        scanKeys();
        uint16_t keys_down = keysDown();

        // Clear console
        consoleClear();

        printf("START: Exit to loader\n");
        printf("A:     Show keyboard\n");
        printf("B:     Hide keyboard\n");
        printf("\n");
        printf("Total space: %zu chars", sizeof(string) - 1);
        printf("\n");
        printf("[%s]\n", string);
        printf("Length: %d\n", strlen(string));

        if (keys_down & KEY_A)
            keyboardShow();

        if (keys_down & KEY_B)
            keyboardHide();

        // keyboardUpdate() returns -1 if there is no active keyboard, or if the
        // keyboard is hidden.
        int16_t c = keyboardUpdate();
        if (c != -1)
        {
            if (c == '\b') // Backspace
            {
                if (string_cursor > 0)
                {
                    string_cursor--;
                    string[string_cursor] = '\0';
                }
            }
            else if (c >= 32)
            {
                // Make sure to leave an empty character for the nul terminator
                if (string_cursor < (sizeof(string) - 1))
                {
                    string[string_cursor] = c;
                    string_cursor++;
                    string[string_cursor] = '\0';
                }
            }
        }

        if (keys_down & KEY_START)
            break;
    }

    return 0;
}
