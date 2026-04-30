#ifndef GAME_H
#define GAME_H

#include "../Engine/Core/IGame.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "../Engine/Systems/InputManager.h"
#include "../Engine/Systems/CollisionSystem.h"

#include <vector>

class Game : public IGame
{
public:
    Game();

    void update(float dt, const InputManager& input) override;
    void render(Renderer& renderer) override;

private:
    Player m_player;
    std::vector<Enemy> m_enemies;
    std::vector<Bullet> m_bullets;

    // InputManager m_input;
    CollisionSystem m_collision;

    bool m_spaceWasPressed = false;

    void updateBullets(float dt);
    void updateEnemies(float dt);
    void handleShooting(const InputManager& input);
    void handleCollisions();
    void removeDeadObjects();
};

#endif