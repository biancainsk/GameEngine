#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

class GameObject;

class CollisionSystem
{
public:
    bool intersects(const GameObject& entity1, const GameObject& entity2) const;
};

#endif