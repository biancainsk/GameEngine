#include <Systems/SpawnerSystem.h>

SpawnerSystem::SpawnerSystem(const SpawnConfig& config)
                    : m_config(config)
{}

bool SpawnerSystem::shouldSpawn(float dt)
{
    m_spawnTimer += dt;

    if (m_spawnTimer >= m_config.spawnInterval)
    {
        m_spawnTimer = 0.0f;
        return true;
    }
    return false;
}

GameObject* SpawnerSystem::spawnEntity(float dt)
{
    GameObject* spawnedEntity = nullptr;

    std::uniform_int_distribution<int> xDist(0, m_config.gameBounds.width);
    std::uniform_int_distribution<int> yDist(0, m_config.gameBounds.height);

    float x = static_cast<float>(xDist(m_randomEngine));
    float y = static_cast<float>(yDist(m_randomEngine));

    spawnedEntity = createObject(Position{x, y});

    return spawnedEntity;
}

void SpawnerSystem::reset()
{
    m_spawnTimer = 0.0f;
}