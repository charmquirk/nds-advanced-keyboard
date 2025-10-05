#include <nds.h>

#include "console.h"
#include "keyboards.h"

PrintConsole outputConsole;


void OutputConsoleInit()
{
    // PrintConsole * 	consoleInitEx (PrintConsole *console, int layer, BgType type,
    // BgSize size, int mapBase, int tileBase, int palIndex, int fontCharOffset,
    // bool mainDisplay, bool loadGraphics)
    // consoleInit(outputConsole, 0, NULL, NULL, 15, NULL, NULL, NULL);
    consoleDemoInit();
}


void OutputConsoleUpdate()
{
    // Clear console
    consoleClear();

    // Console header
    printf("START: Exit to loader\n");
    printf("A:     Show keyboard\n");
    printf("B:     Hide keyboard\n");
    printf("\n");
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
    
    printf("]\n");
}
    

void OutputConsoleCleanup()
{
    consoleClear();
}