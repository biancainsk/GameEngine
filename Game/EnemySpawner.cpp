#include <EnemySpawner.h>
#include "Enemy.h"

void EnemySpawner::initialize(const Size& gameBounds)
{
    m_gameBounds = gameBounds;
}

void EnemySpawner::reset()
{
    m_spawnTimer = 0.0f;
}

bool EnemySpawner::shouldSpawn(float dt)
{
    m_spawnTimer += dt;

    if (m_spawnTimer >= m_spawnInterval)
    {
        m_spawnTimer = 0.0f;
        return true;
    }
    return false;
}

Position EnemySpawner::spawnEnemyPosition()
{
    std::uniform_int_distribution<int> xDist(0, m_gameBounds.width - Enemy::WIDTH);
    std::uniform_int_distribution<int> yDist(0, m_gameBounds.height - Enemy::HEIGHT);

    float x = static_cast<float>(xDist(m_randomEngine));
    float y = static_cast<float>(yDist(m_randomEngine));

    return Position{x, y};
}