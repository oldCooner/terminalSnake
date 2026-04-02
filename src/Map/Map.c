#include "Map.h"

char arrMap[ (ROW_COUNT * COLUMN_COUNT) + 1 ];


int Map_Init();
int Map_Print();

    
int Map_Init()
{
    //fill middle
    int x, y;
    x = y = 0;

    while( y < ROW_COUNT )
    {
        x = 0;

        while( x < COLUMN_COUNT )
        {
            arrMap[ ( y * COLUMN_COUNT ) + x ] = '.';

            x++;
        }

        y++;
    }

    //build walls

    return 1;
}

int Map_Print()
{
    int x, y;
    x = y = 0;

    while( y < ROW_COUNT )
    {

        x = 0;
        while( x < COLUMN_COUNT )
        {
            printf( "%c", arrMap[ y * COLUMN_COUNT + x ] );
            x++;
        }
        
        printf( "\n" );
        y++;
    }

    return 1;
}