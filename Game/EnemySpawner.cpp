#include <EnemySpawner.h>
#include <Enemy.h>

EnemySpawner::EnemySpawner(int screenW, int screenH)
                    : m_screenW(screenW), m_screenH(screenH),
                      m_randomEngine(std::random_device{}())
{}

bool EnemySpawner::shouldSpawn(float dt)
{
    m_spawnTimer += dt;

    if (m_spawnTimer >= m_spawInterval)
    {
        m_spawnTimer = 0.0f;
        return true;
    }
    return false;
}

Enemy EnemySpawner::spawnEnemy()
{
    std::uniform_int_distribution<int> xDist(0, m_screenW - Enemy::WIDTH);
    std::uniform_int_distribution<int> yDist(0, m_screenH - Enemy::HEIGHT);

    float x = static_cast<float>(xDist(m_randomEngine));
    float y = static_cast<float>(yDist(m_randomEngine));

    return Enemy(Position{x, y});
}