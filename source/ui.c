
#include <nds.h>

#include "ui.h"
#include "scriptsBg.h"
#include "console.h"
#include "keyboards.h"


void UserInterfaceInit()
{
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);

    vramSetPrimaryBanks(VRAM_A_MAIN_BG, VRAM_B_LCD, VRAM_C_SUB_BG, VRAM_D_LCD);

    int bg = bgInitSub(3, BgType_Text4bpp, BgSize_T_256x256, 1, 0);

    dmaCopy(scriptsBgTiles, bgGetGfxPtr(bg), scriptsBgTilesLen);
    dmaCopy(scriptsBgMap, bgGetMapPtr(bg), scriptsBgMapLen);
    dmaCopy(scriptsBgPal, BG_PALETTE_SUB, scriptsBgPalLen);

    videoBgEnableSub(3);

    // Move the main screen to the touch screen so that we can actually use the
    // keyboard.
    lcdMainOnBottom();

    OutputConsoleInit();

    TypingInit();
}

void UserInterfaceUpdate()
{
    OutputConsoleUpdate();
    TypingUpdate();
}

void UserInterfaceCleanup()
{
    OutputConsoleCleanup();
    TypingCleanup();
}
