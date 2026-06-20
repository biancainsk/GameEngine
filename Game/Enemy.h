#ifndef ENEMY_H
#define ENEMY_H

#include <Core/GameObject.h>
#include <Core/IMovable.h>
#include <Core/IBehavior.h>

#include <string>

class Enemy : public GameObject, public IMovable, public IBehavior
{
public:
    void update(float dt) override;
    void behave() override;

protected:
    Enemy(const std::string& name, Position position,
          Velocity velocity, Appearance appearance, const GameContext& context);
};

#endif