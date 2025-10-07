#include <nds.h>

#include "scriptsBg.h"
#include "graphics.h"


int bg_console;


void BackgroundsInit()
{
    bg_console = bgInitSub(
        3,                  // int layer
        BgType_Text4bpp,    // BgType type
        BgSize_T_256x256,   // BgSize size
        MB_BG_SCRIPTS,      // int mapBase
        TB_BG_SCRIPTS       // int tileBase
    );
 	
    dmaCopy(scriptsBgTiles, bgGetGfxPtr(bg_console), scriptsBgTilesLen);
    dmaCopy(scriptsBgMap, bgGetMapPtr(bg_console), scriptsBgMapLen);
    dmaCopy(scriptsBgPal, BG_PALETTE_SUB, scriptsBgPalLen);

    // bgSetPriority(bg_console, 3);
}
