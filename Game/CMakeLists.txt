add_library(Game
            Game.cpp
            Player.cpp
            Enemy.cpp
            Bullet.cpp
            # EnemySpawner.cpp
            GameControls.cpp
            ClassicEnemy.cpp
            FastEnemy.cpp
            ClassicEnemySpawner.cpp
            FastEnemySpawner.cpp
)

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Game PUBLIC Engine)