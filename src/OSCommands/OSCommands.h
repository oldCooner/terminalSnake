#ifndef OS_COMMANDS_HEADER_
#define OS_COMMANDS_HEADER_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
#endif

#ifdef __linux__
    #include <time.h>
#endif

int64_t OS_GetCurrentTime(); //int isn't big enough
void OS_Sleep( uint64_t iMillisecondsToSleep );
void OS_ClearScreen();

#endif