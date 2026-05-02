#ifndef GAME_H
#define GAME_H

#include <Core/IGame.h>
#include <Player.h>
#include <Enemy.h>
#include <Bullet.h>
#include <Systems/CollisionSystem.h>
#include <EnemySpawner.h>

#include <vector>

class InputManager;
class Renderer;

class Game : public IGame
{
public:
    void initialize(int screenW, int screenH) override;
    void update(float dt, const InputManager& input) override;
    void render(Renderer& renderer) override;

private:
    Player m_player;
    std::vector<Enemy> m_enemies;
    std::vector<Bullet> m_bullets;
    CollisionSystem m_collision;
    EnemySpawner m_enemySpawner;

    bool m_spaceWasPressed = false;

    void updateBullets(float dt);
    void updateEnemies(float dt);
    void handleShooting(const InputManager& input);
    void handleCollisions();
    void removeDeadObjects();
};

#endif