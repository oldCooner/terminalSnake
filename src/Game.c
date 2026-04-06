#include "Game.h"

int game_init()
{
    char strSent[] = "Initializing the game\n";
    printf(strSent);

    OS_ClearScreen();
    Map_Init();

    return 1;
}

int game_run()
{
    const int64_t iTargetFrameTime = 16; //milliseconds
    int64_t iFrameStartTimeinMilliseconds, iFrameEndTimeinMilliseconds, iActualFrameTime;
    char strSent[] = "Running the game\n";
    printf(strSent);

    while(1)
    {
        iFrameStartTimeinMilliseconds = OS_GetCurrentTime();

        Map_Print();
        printf("\033[H"); //move cursor back to top right (redraw dont' clear)


        iFrameEndTimeinMilliseconds = OS_GetCurrentTime();
        iActualFrameTime = iFrameEndTimeinMilliseconds - iFrameStartTimeinMilliseconds;
        if( iActualFrameTime < iTargetFrameTime )
        {
            OS_Sleep( iTargetFrameTime - iActualFrameTime - 1 );
        }

    }

    return 1;
}

int game_exit()
{
    char strSent[] = "Exiting the game\n";
    printf(strSent);

    return 1;
}