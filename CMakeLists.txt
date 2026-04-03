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
                    "src/Map"
                    "src/OSCommands"
                    )

set(SOURCE_FILES
    src/OSCommands/OSCommands.c
    src/Map/Map.c
    src/Game.c
    src/main.c
    )


add_executable( ${OUTPUT_NAME} ${SOURCE_FILES} )
target_compile_options( ${OUTPUT_NAME} PRIVATE #apply to my code only
                            -fsanitize=address #address sanitization
                            -fno-omit-frame-pointer # asan stack trace
                            -Wall # throw warnings 
                            -Werror # error out on warnings
                            -g )
target_link_options(${OUTPUT_NAME} PRIVATE -fsanitize=address)
target_link_libraries(${OUTPUT_NAME} PRIVATE)