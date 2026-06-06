#ifndef ENEMY_H
#define ENEMY_H

#include <Core/GameObject.h>

class Player;
class Renderer;

class Enemy : public GameObject
{
public:
    // Enemy();
    Enemy(Position position, Velocity velocity);

    void update(float dt) override;
    void render(const Renderer& renderer) const override;

    void setTarget(Position target);
    void followTarget(float dt);

private:
    Position m_target;

    // static constexpr float WIDTH = 30.0f;
    // static constexpr float HEIGHT = 30.0f;
};

#endif