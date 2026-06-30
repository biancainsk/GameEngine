#include <WaveManager.h>
#include <Core/GameObject.h>

#include <algorithm>
#include <iostream>

void WaveManager::reset()
{
    m_waveNumber = 1;
    m_entitiesThisWave = BASE_COUNT;
    m_spawnedThisWave = 0;
    m_interWaveTimer = 0.0f;
    m_state = State::Active;

    m_waveEntitiesIds.clear();
}

void WaveManager::update(float dt)
{
    if (m_state == State::Active)
    {
        if (allSpawned() && m_waveEntitiesIds.empty())
        {
            m_state = State::Waiting;
            m_interWaveTimer = 0.0f;
        }
    }
    else
    {
        m_interWaveTimer += dt;
        if (m_interWaveTimer >= INTER_WAVE_DELAY)
        {
            startNextWave();
        }
    }
}

bool WaveManager::canSpawn() const
{
    return ((m_state == State::Active) && (m_spawnedThisWave < m_entitiesThisWave));
}

void WaveManager::onEntitySpawned(int entityId)
{
    m_waveEntitiesIds.insert(entityId);
    ++m_spawnedThisWave;
}

void WaveManager::onEntityDies(int entityId)
{
    m_waveEntitiesIds.erase(entityId);
}

int WaveManager::currentWave() const
{
    return m_waveNumber;
}

void WaveManager::startNextWave()
{
    ++m_waveNumber;
    m_spawnedThisWave = 0;
    m_entitiesThisWave = BASE_COUNT + (m_waveNumber - 1) * COUNT_INCREMENT;
    m_interWaveTimer = 0.0f;
    m_state = State::Active;

    m_waveEntitiesIds.clear();
}

bool WaveManager::allSpawned() const
{
    return (m_spawnedThisWave >= m_entitiesThisWave);
}