#include <ClassicEnemySpawner.h>
#include <ClassicEnemy.h>
#include <Core/Globals.h>

ClassicEnemySpawner::ClassicEnemySpawner(SpawnConfig config)
    : SpawnerSystem(config)
{
}

GameObject* ClassicEnemySpawner::createObject(Position position)
{
    return new ClassicEnemy(position);
}