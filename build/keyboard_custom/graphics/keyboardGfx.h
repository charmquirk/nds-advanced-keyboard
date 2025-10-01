
//{{BLOCK(keyboardGfx)

//======================================================================
//
//	keyboardGfx, 240x400@4, 
//	Transparent color : 00,00,00
//	+ palette 16 entries, not compressed
//	+ 688 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), not compressed, 30x50 
//	Total size: 32 + 8340 + 3000 = 11372
//
//	Time-stamp: 2025-10-01, 06:18:17
//	Exported by Cearn's GBA Image Transmogrifier, BlocksDS v1.12.0-blocks
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEYBOARDGFX_H
#define GRIT_KEYBOARDGFX_H

#define keyboardGfxTilesLen 8340
extern const unsigned int keyboardGfxTiles[2085];

#define keyboardGfxMapLen 3000
extern const unsigned short keyboardGfxMap[1500];

#define keyboardGfxPalLen 32
extern const unsigned short keyboardGfxPal[16];

#endif // GRIT_KEYBOARDGFX_H

//}}BLOCK(keyboardGfx)
