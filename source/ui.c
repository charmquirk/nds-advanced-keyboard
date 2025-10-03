
#include <nds.h>
#include "scriptsBg.h"
#include "ui.h"
#include "keyboards.h"

// char consoleText[64];

void UserInterfaceInit()
{
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    consoleDemoInit();

    vramSetPrimaryBanks(VRAM_A_MAIN_BG, VRAM_B_LCD, VRAM_C_SUB_BG, VRAM_D_LCD);

    int bg = bgInitSub(3, BgType_Text4bpp, BgSize_T_256x256, 1, 0);

    dmaCopy(scriptsBgTiles, bgGetGfxPtr(bg), scriptsBgTilesLen);
    dmaCopy(scriptsBgMap, bgGetMapPtr(bg), scriptsBgMapLen);
    dmaCopy(scriptsBgPal, BG_PALETTE_SUB, scriptsBgPalLen);

    videoBgEnableSub(3);

    // Move the main screen to the touch screen so that we can actually use the
    // keyboard.
    lcdMainOnBottom();

    TypingInit();
}

void UserInterfaceUpdate()
{
    // Clear console
    consoleClear();

    printf("START: Exit to loader\n");
    printf("A:     Show keyboard\n");
    printf("B:     Hide keyboard\n");
    printf("\n");
    printf("Total space: %zu chars\n", sizeof(string) - 1);
    printf("[%s]\n", string);
    printf("Length: %d\n", strlen(string));

    TypingUpdate();
}
