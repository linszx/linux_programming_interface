cmake_minimum_required(VERSION 3.0.0)
project(Linux_Programming_Interace VERSION 0.1.0)

aux_source_directory(. DIR_LIB_SRCS)
add_library (lib ${DIR_LIB_SRCS})