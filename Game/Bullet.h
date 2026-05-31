#ifndef BULLET_H
#define BULLET_H

#include <Core/GameObject.h>
#include <Core/Globals.h>

class Renderer;

class Bullet : public GameObject
{
public:
    Bullet();
    Bullet(Position pos, Velocity velocity, Heading heading);

    void update(float dt, const Size& gameBounds);
    void render(const Renderer& renderer) const override;
};

#endif