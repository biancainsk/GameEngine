#ifndef SPAWNER_SYSTEM_H
#define SPAWNER_SYSTEM_H

#include <Core/Globals.h>
#include <random>

class GameObject;

struct SpawnConfig
{
    float spawnInterval = 2.0f;
    GameContext context;
};

class SpawnerSystem
{
public:
    explicit SpawnerSystem(const SpawnConfig& config = SpawnConfig());
    virtual ~SpawnerSystem() = default;

    bool shouldSpawn(float dt);
    GameObject* spawnEntity();
    void reset();

protected:
    virtual GameObject* createObject(Position) = 0;

private:
    SpawnConfig m_config;

    float m_spawnTimer = 0.0f;
    std::mt19937 m_randomEngine{std::random_device{}()};
};

#endif