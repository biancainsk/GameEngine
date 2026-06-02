#ifndef GAME_H
#define GAME_H

#include <Core/IGame.h>
#include <Core/GameObject.h>
#include <Player.h>
#include <Core/Globals.h>

#include <vector>

class InputManager;
class CollisionSystem;
class Renderer;
class SpawnerSystem;

enum class GameState
{
    Play,
    GameOver
};

class Game : public IGame
{
public:
    ~Game() override;
    void initialize(const Size& gameBounds) override;
    void update(float dt, const InputManager& input, const CollisionSystem& collision) override;
    void render(const Renderer& renderer) const override;

private:
    Size m_gameBounds;
    GameState m_state = GameState::Play;

    Player m_player;
    std::vector<GameObject*> m_objects;

    SpawnerSystem* m_classicEnemySpawner = nullptr;
    SpawnerSystem* m_fastEnemySpawner = nullptr;

    void restart();
    void setUpSpawners();

    void updateObjects(float dt);
    void renderObjects(const Renderer& renderer) const;
    void updateEnemyTargets();

    void handleShooting(const InputManager& input);
    void handleCollisions(const CollisionSystem& collision);
    void handleSpawning(float dt);

    void removeDeadObjects();
    void destroyObjects();
    void destroySpawners();
};

#endif