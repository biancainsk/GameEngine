#ifndef FAST_ENEMY_SPAWNER_H
#define FAST_ENEMY_SPAWNER_H

#include <Systems/SpawnerSystem.h>

class GameObject;
struct Position;

class FastEnemySpawner : public SpawnerSystem
{
public:
    explicit FastEnemySpawner(SpawnConfig config);

protected:
    GameObject* createObject(Position position, const GameContext& context) override;
};

#endif