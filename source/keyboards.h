#include <nds.h>

extern int keyboardIndex;
extern Keyboard *customKeyboard;
extern char string[50];
extern int string_cursor;
extern int string_length;

extern const void TypingInit();
extern const void TypingUpdate();
extern const void TypingCleanup();
extern void InsertChar(int index, char c);
extern void RemoveChar(int index);
extern void SetKeyboard(int index);
