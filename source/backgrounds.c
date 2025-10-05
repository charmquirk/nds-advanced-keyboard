#include <nds.h>

#include "scriptsBg.h"


int bg_console;


void BackgroundsInit()
{
    bg_console = bgInitSub(3,
        BgType_Text4bpp,    // int layer
        BgSize_T_256x256,   // BgType type
        1,                  // int mapBase
        0                   // int tileBase
    );
 	
    dmaCopy(scriptsBgTiles, bgGetGfxPtr(bg_console), scriptsBgTilesLen);
    dmaCopy(scriptsBgMap, bgGetMapPtr(bg_console), scriptsBgMapLen);
    dmaCopy(scriptsBgPal, BG_PALETTE_SUB, scriptsBgPalLen);
}
