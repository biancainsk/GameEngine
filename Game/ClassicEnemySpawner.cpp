#include <ClassicEnemySpawner.h>
#include <ClassicEnemy.h>
#include <Core/Globals.h>

ClassicEnemySpawner::ClassicEnemySpawner(SpawnConfig config)
    : SpawnerSystem(config)
{
}

GameObject* ClassicEnemySpawner::createObject(Position position, const GameContext& context)
{
    return new ClassicEnemy(position, context);
}