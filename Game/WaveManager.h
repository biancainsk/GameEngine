#ifndef WAVE_MANAGER_H
#define WAVE_MANAGER_H

#include <unordered_set>
#include <cstdint>

class GameObject;

class WaveManager
{
public:
    enum class State
    {
        Active,
        Waiting
    };

    void reset();
    void update(float dt);

    bool canSpawn() const;
    void onEntitySpawned(int entityId);
    void onEntityDies(int entityId);

    int currentWave() const;

private:
    static constexpr int BASE_COUNT = 4;
    static constexpr int COUNT_INCREMENT = 2;
    static constexpr float INTER_WAVE_DELAY = 2.0f;

    void startNextWave();
    bool allSpawned() const;

    int m_waveNumber = 1;
    int m_entitiesThisWave = BASE_COUNT;
    int m_spawnedThisWave = 0;
    float m_interWaveTimer = 0.0f;
    State m_state = State::Active;

    std::unordered_set<int> m_waveEntitiesIds;
};

#endif