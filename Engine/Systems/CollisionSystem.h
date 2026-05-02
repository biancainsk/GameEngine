#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <Core/Globals.h>

class CollisionSystem
{
public:
    bool intersects(Position Entity1Pos, Position Entity2Pos,
                    Size Entity1Size, Size Entity2Size);
};

#endif