cmake_minimum_required(VERSION 3.10)

project(chip-eat)

# # --- Compile SDL ---
add_subdirectory(dep/SDL)
include_directories(dep/SDL/include)
set(SDL_LIBS SDL2 SDL2main)

# # --- Compile actual project ---
include_directories(include)

add_executable(main src/main.c src/chip.c src/app.c)
target_link_libraries(main ${SDL_LIBS})