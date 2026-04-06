#include "KeyboardHandler.h"

#ifdef __linux__
    struct termios sOriginalTerminal;
#endif

void Keyboard_EnableRawMode( struct termios *pInputTerminal )
{
#ifdef __linux__
    // disable canonical mode
    pInputTerminal->c_cflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &pInputTerminal );
#endif
}

void Keyboard_RestoreTerminal( )
{
#ifdef __linux
    restore_terminal( &sOriginalTerminal );
#endif
}

int Keyboard_Init()
{
#ifdef __linux__
    tcgetattr( STDIN_FILENO, &sOriginalTerminal ); // get original state of the terminal
    atexit( Keyboard_RestoreTerminal ); // Restore on exit

    Keyboard_EnableRawMode( &sOriginalTerminal );

#endif

    return 1;
}
