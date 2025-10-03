
//{{BLOCK(keyboardGfx)

//======================================================================
//
//	keyboardGfx, 256x384@4, 
//	Transparent color : 00,00,00
//	+ palette 16 entries, not compressed
//	+ 863 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), not compressed, 32x48 
//	Total size: 32 + 10060 + 3072 = 13164
//
//	Time-stamp: 2025-10-02, 23:28:06
//	Exported by Cearn's GBA Image Transmogrifier, BlocksDS v1.12.0-blocks
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_KEYBOARDGFX_H
#define GRIT_KEYBOARDGFX_H

#define keyboardGfxTilesLen 10060
extern const unsigned int keyboardGfxTiles[2515];

#define keyboardGfxMapLen 3072
extern const unsigned short keyboardGfxMap[1536];

#define keyboardGfxPalLen 32
extern const unsigned short keyboardGfxPal[16];

#endif // GRIT_KEYBOARDGFX_H

//}}BLOCK(keyboardGfx)
