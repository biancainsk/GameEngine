#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class InputManager;
class Bullet;

class Player : public GameObject
{
public:
    Player();

    void update(float dt, const InputManager& input);
    void render(Renderer& renderer) override;

    Bullet shoot() const;
};

#endif