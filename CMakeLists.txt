cmake_minimum_required(VERSION 3.16)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

link_libraries(ssl)
link_libraries(crypto)
add_executable(CourseWork main.cpp sha256.h sha256.cpp miner.h miner.cpp proof.h proof.cpp input.h input.cpp)