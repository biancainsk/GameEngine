#ifndef BULLET_H
#define BULLET_H

#include <Core/GameObject.h>
#include <Core/IMovable.h>
#include <Core/Globals.h>

class Bullet : public GameObject, public IMovable
{
public:
    Bullet(Position position, Velocity velocity, Heading heading, const GameContext& context);

    void update(float dt) override;
};

#endif