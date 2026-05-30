#ifndef PLAYER_H
#define PLAYER_H

#include <Core/GameObject.h>

class InputManager;
class Renderer;
class Bullet;

class Player : public GameObject
{
public:
    Player();

    void update(float dt, const InputManager& input);
    void render(const Renderer& renderer) const override;

    Velocity getShootVelocity() const;
    Heading getShootHeading() const;
};

#endif