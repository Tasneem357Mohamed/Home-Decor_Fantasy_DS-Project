cmake_minimum_required(VERSION 3.28)
project(Home_Decor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(Home_Decor main.cpp
        Home_Decor.cpp
        Home_Decor.h
)
include_directories(/usr/local/include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Home_Decor sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
