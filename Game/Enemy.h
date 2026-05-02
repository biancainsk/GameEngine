#ifndef ENEMY_H
#define ENEMY_H

#include <GameObject.h>

class Player;
class Renderer;

class Enemy : public GameObject
{
public:
    Enemy();

    void update(float dt, const Player& player);
    void render(Renderer& renderer) override;
};

#endif