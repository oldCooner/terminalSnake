#ifndef MAP_HEADER_
#define MAP_HEADER_

#define ROW_COUNT 100
#define COLUMN_COUNT 50

// the map will be an array of chars
// row major
// access [x][y] with (y * ROW_COUNT + x)
char arrMap[ ROW_COUNT * COLUMN_COUNT ];


int Map_Init();

#endif