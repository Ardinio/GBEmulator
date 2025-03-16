cmake_minimum_required(VERSION 3.10)
project(GBEmulator C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
file(GLOB_RECURSE SOURCES 
    "src/*.c"
    "src/cpu/*.c"
    "src/memory/*.c"
    "src/ppu/*.c"
    "src/apu/*.c"
    "src/cartridge/*.c"
)

# Create executable
add_executable(gbemu ${SOURCES})

# Link SDL2
target_link_libraries(gbemu ${SDL2_LIBRARIES}) 