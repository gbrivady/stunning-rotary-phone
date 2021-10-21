#CMake min version
cmake_minimum_required(VERSION 3.13)

#Project info
project(StunningRotaryPhone VERSION 0.1.0)

#look for sfml
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/Modules)
find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
#add the exes
add_subdirectory(src)
#add_subdirectory(test)
#if(${CMAKE_BUILD_TYPE} STREQUAL Release)
#    target_link_options(StunningRotaryPhone PRIVATE -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread)
#endif()
