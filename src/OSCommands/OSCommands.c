#include "OSCommands.h"

int64_t OS_GetCurrentTime()
{
    int64_t iCurrentTimeinMilliseconds;
    iCurrentTimeinMilliseconds = 0;

#ifdef _WIN32
    static LARGE_INTEGER frequency;
    static int initialized = 0;

    if (!initialized)
    {
        QueryPerformanceFrequency(&frequency);
        initialized = 1;
    }

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    iCurrentTimeinMilliseconds = (counter.QuadPart * 1000) / frequency.QuadPart;
#endif
    

#ifdef __linux__
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);

    iCurrentTimeinMilliseconds = (int64_t)spec.tv_sec * 1000 + (spec.tv_nsec / 1000000);
#endif

    if( ! iCurrentTimeinMilliseconds )
    {
        fprintf( stderr, "FATAL: Failed to get system time" );
        exit(EXIT_FAILURE);
    } else
    {
        return iCurrentTimeinMilliseconds;
    }
}

void OS_Sleep( uint64_t iMillisecondsToSleep )
{
#ifdef _WIN32
    Sleep( iMillisecondsToSleep );
#endif

#ifdef __linux__
    struct timespec ts;
    ts.tv_sec = iMillisecondsToSleep / 1000;
    ts.tv_nsec = ( iMillisecondsToSleep % 1000 ) * 1000000L;
    nanosleep( &ts, NULL );
#endif
}