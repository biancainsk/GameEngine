add_library(Game
            Game.cpp
            GameObject.cpp
            Player.cpp
            Enemy.cpp
            Bullet.cpp
)

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Game PUBLIC Engine)