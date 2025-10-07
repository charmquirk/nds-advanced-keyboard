#include <nds.h>

#include "console.h"
#include "keyboards.h"
// #include "backgrounds.h"
#include "graphics.h"

#define CONSOLE_WINDOW_OFFSET_X 3
#define CONSOLE_WINDOW_OFFSET_Y 5
#define CONSOLE_WINDOW_WIDTH 30 + CONSOLE_WINDOW_OFFSET_X
#define CONSOLE_WINDOW_HEIGHT 10 + CONSOLE_WINDOW_OFFSET_Y


PrintConsole outputConsole =
{
    // .font =
    // {
    //     .gfx = default_fontTiles, // Font tiles
    //     .pal = NULL,              // No font palette (use the default palettes)
    //     .numColors = 0,
    //     .bpp = 1,
    //     .asciiOffset = 32,        // First ASCII character in the set
    //     .numChars = 96            // Number of characters in the font set
    // },
 
    .consoleWidth = 32,
    .consoleHeight = 24,
    .windowX = CONSOLE_WINDOW_OFFSET_X,
    .windowY = CONSOLE_WINDOW_OFFSET_Y,
    .windowWidth = CONSOLE_WINDOW_WIDTH,
    .windowHeight = CONSOLE_WINDOW_HEIGHT,
    .tabSize = 3,
    .PrintChar = NULL,
};


void OutputConsoleInit()
{
    consoleInit(&outputConsole,     // PrintConsole *console
        0,                          // int layer
        BgType_Text4bpp,            // BgType type
        BgSize_T_256x256,           // BgSize size
        MB_BG_CONSOLE,              // int mapBase      bgGetMapBase(bg_console)?
        TB_BG_CONSOLE,              // int tileBase      bgGetTileBase(bg_console)?
        false,                      // bool mainDisplay
        true                        // bool loadGraphics
    );

    // bgSetPriority(0, 0);
    consoleSetWindow(
        &outputConsole,             // PrintConsole *console
        CONSOLE_WINDOW_OFFSET_X,    // int offset x (in tiles)
        CONSOLE_WINDOW_OFFSET_Y,    // int offset y (in tiles)
        CONSOLE_WINDOW_WIDTH,       // int width (in tiles)
        CONSOLE_WINDOW_HEIGHT       // int height (in tiles)
    );
}


void OutputConsoleUpdate()
{
    // Clear console
    consoleClear();

    // Console header
    printf("START: Exit to loader\n");
    printf("A:     Show keyboard\n");
    printf("B:     Hide keyboard\n\n");

    printf("Total space: %zu chars\n", sizeof(string) - 1);
    printf("Length: %d, Cursor: %d\n", string_length, string_cursor);
    printf("[");
    
    // Print characters before cursor
    for (int i = 0; i < string_cursor; i++)
    {
        printf("%c", string[i]);
    }
    
    // Print cursor
    printf("|");
    
    // Print characters after cursor
    for (int i = string_cursor; i < string_length; i++)
    {
        printf("%c", string[i]);
    }
    
    printf("]\n\n");
    printf("Keyboard: %d\n", keyboardIndex);
    printf("Pointer: %p\n", customKeyboard);
    printf("X:     Next keyboard\n");
    printf("Y:     Previous keyboard\n\n");
}
    

void OutputConsoleCleanup()
{
    consoleClear();
}