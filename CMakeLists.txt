cmake_minimum_required(VERSION 3.0.0)
project(Linux_Programming_Interace VERSION 0.1.0)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_link_options(-Wl,-rpath=/home/shu/Study/glibc-2.35/install/lib)

include_directories(include/lib)

add_subdirectory(src/lib)

link_libraries(lib)
add_subdirectory(src/fileio)
add_subdirectory(src/proc)
