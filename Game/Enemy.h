#ifndef ENEMY_H
#define ENEMY_H

#include <GameObject.h>

class Player;
class Renderer;

class Enemy : public GameObject
{
public:
    Enemy();
    Enemy(Position pos);

    void update(float dt, const Player& player);
    void render(Renderer& renderer) override;

    static constexpr float WIDTH = 30.0f;
    static constexpr float HEIGHT = 30.0f;
};

#endif