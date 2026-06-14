#include <FastEnemySpawner.h>
#include <FastEnemy.h>
#include <Core/Globals.h>

FastEnemySpawner::FastEnemySpawner(SpawnConfig config)
    : SpawnerSystem(config)
{
}

GameObject* FastEnemySpawner::createObject(Position position, const GameContext& context)
{
    return new FastEnemy(position, context);
}