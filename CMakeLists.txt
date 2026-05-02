cmake_minimum_required(VERSION 3.16)
project(GameEngine VERSION 0.1.0 LANGUAGES C CXX)

# Set CXX standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add source directories
add_subdirectory(Engine)
add_subdirectory(Game)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE Engine Game)