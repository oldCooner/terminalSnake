#ifndef MAP_HEADER_
#define MAP_HEADER_

#define ROW_COUNT 25
#define COLUMN_COUNT 50

#include <stdio.h>

// the map will be an array of chars
// row major
// access [x][y] with (y * COLUMN_COUNT + x)
extern char arrMap[ (ROW_COUNT * COLUMN_COUNT) + 1 ];


int Map_Init();
int Map_Print();

#endif