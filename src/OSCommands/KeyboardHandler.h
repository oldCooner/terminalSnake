#ifndef KEYBOARD_HANDLER_HEADER_
#define KEYBOARD_HANDLER_HEADER_

#include <stdlib.h>

#ifdef __linux__
    #include <termios.h>
    #include <unistd.h>
    
    extern struct termios sOriginalTerminal;
#endif

enum _KEYBOARD_KEYS
{
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D,
    KEY_UP,
    KEY_LEFT,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_ESC,
    KEY_Q,
    SUPPORTED_KEY_COUNT
};

extern int arrKeyboardKeyState[SUPPORTED_KEY_COUNT];

int Keyboard_Init();
int Keyboard_Exit();
void Keyboard_EnableRawMode( struct termios *pInputTerminal );
void Keyboard_RestoreTerminal( struct termios *pInputTerminal );

void Keyboard_ScanKeyBoard();

#endif