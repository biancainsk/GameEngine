#ifndef CLASSIC_ENEMY_SPAWNER_H
#define CLASSIC_ENEMY_SPAWNER_H

#include <Systems/SpawnerSystem.h>

class GameObject;
struct Position;

class ClassicEnemySpawner : public SpawnerSystem
{
public:
    explicit ClassicEnemySpawner(SpawnConfig config);

protected:
    GameObject* createObject(Position position) override;
};

#endif