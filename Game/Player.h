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
    void render(Renderer& renderer) override;

    Bullet shoot() const;

private:
    Velocity m_trajectory = {0.0f, 0.0f};
};

#endif