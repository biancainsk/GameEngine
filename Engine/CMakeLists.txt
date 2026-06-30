add_library(Engine
            Core/Engine.cpp
            Core/Renderer.cpp
            Core/Window.cpp
            Core/GameObject.cpp
            Core/IMovable.cpp
            Core/IBehavior.cpp
            Core/TextRenderer.cpp
            Systems/InputManager.cpp
            Systems/CollisionSystem.cpp
            Systems/SpawnerSystem.cpp
)

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(Engine PUBLIC SDL2::SDL2)

# SDL2_ttf — 2.0.18 ships no CMake config, locate it manually
find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf REQUIRED)
find_path(SDL2_TTF_INCLUDE_DIR NAMES SDL_ttf.h PATH_SUFFIXES SDL2 REQUIRED)

target_include_directories(Engine PUBLIC ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Engine PUBLIC ${SDL2_TTF_LIBRARY}) 