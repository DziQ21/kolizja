cmake_minimum_required(VERSION 2.51)
project(SquareAndCircle)



set(CMAKE_CXX_STANDARD 14)
add_executable(SquareAndCircle main.cpp source/rectangle.cpp include source/circle.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(SquareAndCircle sfml-system sfml-window sfml-graphics)