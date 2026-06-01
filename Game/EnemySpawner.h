#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include <Core/Globals.h>
#include <random>

class EnemySpawner
{
public:
    EnemySpawner() = default;

    void initialize(const Size& gameBounds);
    void reset();
    bool shouldSpawn(float dt);
    Position spawnEnemyPosition();

private:
    Size m_gameBounds;

    float m_spawnTimer = 0.0f;
    float m_spawnInterval = 2.0f;

    std::mt19937 m_randomEngine;
};

#endif