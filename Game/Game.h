#ifndef GAME_H
#define GAME_H

#include <Core/IGame.h>

#include <Player.h>
#include <Enemy.h>
#include <Bullet.h>
#include <EnemySpawner.h>

#include <vector>

class InputManager;
class CollisionSystem;
class Renderer;

enum class GameState
{
    GameOver,
    Play
};

class Game : public IGame
{
public:
    void initialize(int screenW, int screenH) override;
    void update(float dt, const InputManager& input, const CollisionSystem& collision) override;
    void render(const Renderer& renderer) const override;
    void restart();

private:
    Player m_player;
    std::vector<Enemy> m_enemies;
    std::vector<Bullet> m_bullets;

    EnemySpawner m_enemySpawner;

    int m_screenWidth = 0;
    int m_screenHeight = 0;

    bool m_spaceWasPressed = false;
    GameState m_state = GameState::Play;

    void updateBullets(float dt);
    void updateEnemies(float dt);
    void handleShooting(const InputManager& input);
    void handleCollisions(const CollisionSystem& collision);
    void removeDeadObjects();
};

#endif