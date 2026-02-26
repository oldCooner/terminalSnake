cmake_minimum_required(VERSION 3.16)

### Definitions
set(PROJECT_NAME terminalSnake)
set(OUTPUT_NAME ${PROJECT_NAME}.out)
project( ${PROJECT_NAME} VERSION 1.0)

### Setup output dir
### required for ttf librariesd
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")

### Dependencies
include_directories("src"
                    )

set(SOURCE_FILES
    src/Game.c
    src/main.c
    )


add_executable( ${OUTPUT_NAME} ${SOURCE_FILES} )
target_compile_options( ${OUTPUT_NAME} PRIVATE -Wall -Werror -g ) # warning failures for me only
target_link_libraries(${OUTPUT_NAME} PRIVATE)