add_library(Aurora STATIC)


target_sources(
    Aurora

    PRIVATE

    Source/Core/Application.cpp
    Source/Core/Logger.cpp
    Source/Core/Window.cpp
    Source/Core/Time.cpp
)


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


