add_library(Aurora STATIC)

file(GLOB_RECURSE AURORA_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp
)

target_sources(Aurora PRIVATE ${AURORA_SOURCES})


target_include_directories(
    Aurora

    PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

find_package(SDL3 REQUIRED)

target_link_libraries(
    Aurora

    PRIVATE

    SDL3::SDL3
)


