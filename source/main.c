// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2024

#include <stdio.h>
#include <nds.h>
#include "keyboards.h"
#include "keyboardGfx.h"


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
