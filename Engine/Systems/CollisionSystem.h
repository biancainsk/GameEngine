#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <Core/GameObject.h>

class CollisionSystem
{
public:
    bool intersects(const GameObject& entity1, const GameObject& entity2);
};

#endif