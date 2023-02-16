cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

project(chip-eat)

# # --- Compile SDL ---
add_subdirectory(dep/SDL)
include_directories(dep/SDL/include)
set(SDL_LIBS SDL2 SDL2main)

# # --- Compile actual project ---
include_directories(include)

add_executable(main src/main.c src/chip.c src/app.c src/timers.c)
target_link_libraries(main ${SDL_LIBS})