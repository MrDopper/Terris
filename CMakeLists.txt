cmake_minimum_required(VERSION 3.15)
project(Terris)

find_package(raylib REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
