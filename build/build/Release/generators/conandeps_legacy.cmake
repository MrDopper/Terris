message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(raylib)
find_package(ZLIB)

set(CONANDEPS_LEGACY  raylib  ZLIB::ZLIB )