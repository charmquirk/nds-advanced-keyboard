#include <nds.h>
#include "keyboards.h"
#include "kbd_godot.h"
#include "kbd_numeric.h"


char string[50];
int string_cursor;
int string_length;
enum input_mode {
    NONE,
    KEYBOARD,
    WHEEL,
    GESTURE
};

#define KEYBOARD_COUNT 2
int keyboardIndex;
Keyboard *customKeyboard;
const Keyboard *keyboards[KEYBOARD_COUNT] =
{
    &kbdGodot,
    &kbdNumeric
};


void TypingInit()
{
    string[0] = '\0';
    string_cursor = 0;
    string_length = 0;
    
    SetKeyboard(0);
}

void TypingUpdate()
{
    // keyboardUpdate() returns -1 if there is no active keyboard, or if the
    // keyboard is hidden.
    int16_t c = keyboardUpdate();
    if (c != -1)
    {
        if (c == '\b') // Backspace
        {
            RemoveChar(string_cursor-1);
        }
        else if (c >= 32)
        {
            InsertChar(string_cursor, c);
        }
        else if (c == DVK_LEFT)
        {
            if (string_cursor > 0)
                string_cursor--;
        }
        else if (c == DVK_RIGHT)
        {
            if (string_cursor < string_length)
                string_cursor++;
        }
        else if (c == DVK_UP)
        {
            string_cursor = string_length;
        }
        else if (c == DVK_DOWN)
        {
            string_cursor = 0;
        }
        // else if (c == DVK_DELETE)
        // {
        //     RemoveChar(&string, string_length, string_cursor);
        // }
    }
}

void TypingCleanup()
{
    keyboardHide();
    keyboardExit();
}

void InsertChar(int index, char c)
{
    if (string_length < (sizeof(string) - 1) && index >= 0 && index <= string_length)
    {
        // Shift characters to the right to make space
        for (int i = string_length; i > index; i--)
        {
            string[i] = string[i - 1];
        }
        
        // Insert the new character
        string[index] = c;
        
        string_cursor++;
        string_length++;
        string[string_length] = '\0';
    }
}

void RemoveChar(int index)
{
    if (string_length > 0 && index >= 0 && index < string_length)
    {
        // Shift characters to the left to fill the gap
        for (int i = index; i < string_length - 1; i++)
        {
            string[i] = string[i + 1];
        }
        
        string_length--;
        string[string_length] = '\0'; // Always keep null terminator
        
        // Move cursor back if not at beginning
        if (string_cursor > 0)
            string_cursor--;
    }
}

void SetKeyboard(int index)
{
    // Set the next index
    if (index < 0 || index >= KEYBOARD_COUNT) {
        // Wrap around the current range
        index = ((index % KEYBOARD_COUNT) + KEYBOARD_COUNT) % KEYBOARD_COUNT;
    }

    if (index == keyboardIndex && customKeyboard != NULL)
        return;

    keyboardIndex = index;

    // Set the next keyboard
    if (index >= 0 && index < KEYBOARD_COUNT)
    {
        customKeyboard = keyboards[keyboardIndex];
    }
    else{
        customKeyboard = NULL;
    }
    
    keyboardExit();

    // Load/init the keyboard
    if (customKeyboard == NULL)
    {
        keyboardDemoInit();
    }
    else{
        // Initialize the keyboard and load its graphics
        keyboardInit(customKeyboard,
                 1,                // Background layer to use
                 BgType_Text4bpp,  // 16 color palette format
                 BgSize_T_256x512, // Background size
                 20,               // Map base
                 0,                // Tile base
                 true,             // Display it on the main screen
                 true);            // Load graphics to VRAM
    }   
}