#include <Systems/SpawnerSystem.h>

SpawnerSystem::SpawnerSystem(const SpawnConfig& config)
                    : m_config(config)
{}

GameObject* SpawnerSystem::spawnEntity(float dt)
{
    m_spawnTimer += dt;

    if (m_spawnTimer < m_config.spawnInterval)
        return nullptr;

    m_spawnTimer = 0.0f;

    std::uniform_int_distribution<int> xDist(0, m_config.context.bounds.width);
    std::uniform_int_distribution<int> yDist(0, m_config.context.bounds.height);

    float x = static_cast<float>(xDist(m_randomEngine));
    float y = static_cast<float>(yDist(m_randomEngine));

    return createObject(Position{x, y}, m_config.context);
}

void SpawnerSystem::reset()
{
    m_spawnTimer = 0.0f;
}