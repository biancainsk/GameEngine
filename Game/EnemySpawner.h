#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include <random>

class Enemy;

class EnemySpawner
{
public:
    EnemySpawner() = default;
    EnemySpawner(int screenW, int screenH);

    bool shouldSpawn(float dt);
    Enemy spawnEnemy();

private:
    int m_screenW;
    int m_screenH;

    float m_spawnTimer = 0.0f;
    float m_spawInterval = 2.0f;

    std::mt19937 m_randomEngine;
};

#endif