#include <Systems/CollisionSystem.h>
#include <Core/GameObject.h>
#include <Core/Globals.h>

bool CollisionSystem::intersects(const GameObject& entity1, const GameObject& entity2) const
{
    const Position entity1Pos = entity1.getPosition();
    const Position entity2Pos = entity2.getPosition();

    const Size entity1Size = entity1.getAppearance().size;
    const Size entity2Size = entity2.getAppearance().size;

    return entity1Pos.x - entity1Size.width  / 2.0f < entity2Pos.x + entity2Size.width  / 2.0f &&
           entity1Pos.x + entity1Size.width  / 2.0f > entity2Pos.x - entity2Size.width  / 2.0f &&
           entity1Pos.y - entity1Size.height / 2.0f < entity2Pos.y + entity2Size.height / 2.0f &&
           entity1Pos.y + entity1Size.height / 2.0f > entity2Pos.y - entity2Size.height / 2.0f;
}