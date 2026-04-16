#include "KeyboardHandler.h"

#ifdef __linux__
    struct termios sOriginalTerminal;
#endif

void Keyboard_EnableRawMode( struct termios *pInputTerminal )
{
#ifdef __linux__
    struct termios raw;;
    tcgetattr( STDIN_FILENO, pInputTerminal ); // get original settings
    raw = *pInputTerminal;

    // disable canonical mode and echo
    raw.c_lflag &= ~(ICANON | ECHO );

    // set minimum chars to read to 1 with no tiempot
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    tcsetattr( STDIN_FILENO, TCSANOW, &raw );
#endif
}

void Keyboard_RestoreTerminal( struct termios *pInputTerminal )
{
#ifdef __linux
    tcsetattr( STDIN_FILENO, TCSANOW, pInputTerminal );
#endif
}

int Keyboard_Init()
{
#ifdef __linux__
    Keyboard_EnableRawMode( &sOriginalTerminal );
#endif

    return 1;
}

int Keyboard_Exit()
{
#ifdef __linux__
    Keyboard_RestoreTerminal( &sOriginalTerminal );
#endif

    return 1;
}