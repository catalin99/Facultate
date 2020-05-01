cmake_minimum_required(VERSION 3.12)
project(ProjRC)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjRCserver server.cpp serverProfil.cpp serverProfil.h)
add_executable(ProjRCclient client.cpp)
target_link_libraries(ProjRCserver pthread)
target_link_libraries(ProjRCclient pthread)