
//{{BLOCK(keyboardGfx)

//======================================================================
//
//	keyboardGfx, 256x384@4, 
//	Transparent color : 00,00,00
//	+ palette 16 entries, not compressed
//	+ 827 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), not compressed, 32x48 
//	Total size: 32 + 9684 + 3072 = 12788
//
//	Time-stamp: 2025-10-02, 19:56:41
//	Exported by Cearn's GBA Image Transmogrifier, BlocksDS v1.12.0-blocks
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEYBOARDGFX_H
#define GRIT_KEYBOARDGFX_H

#define keyboardGfxTilesLen 9684
extern const unsigned int keyboardGfxTiles[2421];

#define keyboardGfxMapLen 3072
extern const unsigned short keyboardGfxMap[1536];

#define keyboardGfxPalLen 32
extern const unsigned short keyboardGfxPal[16];

#endif // GRIT_KEYBOARDGFX_H

//}}BLOCK(keyboardGfx)
