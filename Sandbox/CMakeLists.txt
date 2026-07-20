add_executable(
    Sandbox
    Source/main.cpp
)

target_sources(
    Aurora

    PRIVATE

    Source/SandboxLayer.cpp
)


target_link_libraries(
    Sandbox

    PRIVATE

    Aurora
)

