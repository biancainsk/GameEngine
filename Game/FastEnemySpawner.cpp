#include <FastEnemySpawner.h>
#include <FastEnemy.h>
#include <Core/Globals.h>

FastEnemySpawner::FastEnemySpawner(SpawnConfig config)
    : SpawnerSystem(config)
{
}

GameObject* FastEnemySpawner::createObject(Position position)
{
    return new FastEnemy(position);
}