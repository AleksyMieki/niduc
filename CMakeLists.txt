cmake_minimum_required(VERSION 3.21)
project(niduc)

set(CMAKE_CXX_STANDARD 14)

add_executable(niduc main.cpp  FILE_SERVICE/DataReader.cpp FILE_SERVICE/DataReader.h FILE_SERVICE/Encryption.cpp FILE_SERVICE/Encryption.h BBS.cpp BBS.h)
