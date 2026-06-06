#include <Systems/CollisionSystem.h>
#include <Core/Globals.h>

bool CollisionSystem::intersects(const GameObject& entity1, const GameObject& entity2) const
{
    Position entity1Pos = entity1.getPosition();
    Position entity2Pos = entity2.getPosition();

    Size entity1Size = entity1.getSize();
    Size entity2Size = entity2.getSize();

    return entity1Pos.x - entity1Size.width  / 2.0f < entity2Pos.x + entity2Size.width  / 2.0f &&
           entity1Pos.x + entity1Size.width  / 2.0f > entity2Pos.x - entity2Size.width  / 2.0f &&
           entity1Pos.y - entity1Size.height / 2.0f < entity2Pos.y + entity2Size.height / 2.0f &&
           entity1Pos.y + entity1Size.height / 2.0f > entity2Pos.y - entity2Size.height / 2.0f;
}