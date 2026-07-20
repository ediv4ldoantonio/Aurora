cmake_minimum_required(VERSION 3.20)

project(Aurora)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(
    CMAKE_CXX_STANDARD
    20
)

set(CMAKE_PREFIX_PATH
    ${CMAKE_SOURCE_DIR}/ThirdParty/SDL-install
)

add_subdirectory(Engine)

add_subdirectory(Sandbox)