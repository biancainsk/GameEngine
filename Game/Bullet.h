#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:
    Bullet();
    Bullet(Position pos, Velocity velocity);

    void update(float dt);
    void render(Renderer& renderer) override;
};

#endif