#include <nds.h>

extern const Keyboard customKeyboard;
extern char string[50];
extern int string_cursor;

extern const void TypingInit();
extern const void TypingUpdate();
extern const void TypingCleanup();
extern void AddChar(int index, char c);
extern void RemoveChar(int index);
