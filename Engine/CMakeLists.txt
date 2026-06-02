add_library(Engine
            Core/Engine.cpp
            Core/Renderer.cpp
            Core/Window.cpp
            Core/GameObject.cpp
            Systems/InputManager.cpp
            Systems/CollisionSystem.cpp
            Systems/SpawnerSystem.cpp
)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(Engine PUBLIC SDL2::SDL2)