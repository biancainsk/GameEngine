#include <Systems/CollisionSystem.h>

bool CollisionSystem::intersects(Position Entity1Pos, Position Entity2Pos,
                                 Size Entity1Size, Size Entity2Size)
{
    return Entity1Pos.x < Entity2Pos.x + Entity2Size.width &&
           Entity1Pos.x + Entity1Size.width > Entity2Pos.x &&
           Entity1Pos.y < Entity2Pos.y + Entity2Size.height &&
           Entity1Pos.y + Entity1Size.height > Entity2Pos.y;
}