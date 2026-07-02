#!/usr/bin/env bash
set -e
#These commands are for cleanup
#Note: Only use this script when use a new library in conan
rm -rf build
rm -rf CMakeFiles
rm -f CMakecache.txt Makefile cmake_install.cmake
rm -f CMakeUserPresets.json

#Setup conan library
conan install . --build=missing -s build_type=Release -o "*:shared=True"
cmake --preset conan-release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build --preset conan-release

#Run the excuteable file
source "$(find . -name conanrun.sh -print -quit)"
