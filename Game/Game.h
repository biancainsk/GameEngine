#ifndef GAME_H
#define GAME_H

#include <Core/IGame.h>
#include <Player.h>
#include <Bullet.h>
#include <Enemy.h> 
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
    Game() = default;
    ~Game() override;
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void initialize(const Size& gameBounds) override;
    void update(float dt, const InputManager& input, const CollisionSystem& collision) override;
    void render(const Renderer& renderer) const override;

private:
    GameContext m_context;
    GameState m_state = GameState::Play;

    Player m_player;
    std::vector<Enemy*> m_enemies;
    std::vector<Bullet*> m_bullets;

    SpawnerSystem* m_classicEnemySpawner = nullptr;
    SpawnerSystem* m_fastEnemySpawner = nullptr;

    void restart();
    void setUpSpawners();

    void updateEnemies(float dt);
    void updateBullets(float dt);
    void renderEnemies(const Renderer& renderer) const;
    void renderBullets(const Renderer& renderer) const;
    void updateEnemyTargets();

    void handleShooting(const InputManager& input);
    void handleCollisions(const CollisionSystem& collision);
    void handleSpawning(float dt);

    void removeDeadObjects();
    void destroyObjects();
    void destroySpawners();

    static constexpr int MAX_ENEMIES = 32;
    static constexpr int MAX_BULLETS = 64;
};

#endif