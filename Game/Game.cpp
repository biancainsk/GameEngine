#include <Game.h>
#include <Systems/InputManager.h>
#include <Systems/CollisionSystem.h>
#include <Core/Renderer.h>
#include <GameControls.h>

#include <Systems/SpawnerSystem.h>
#include <ClassicEnemySpawner.h>
#include <FastEnemySpawner.h>

#include <algorithm>

Game::~Game()
{
    destroyObjects();
    destroySpawners();
}

void Game::initialize(const Size& gameBounds)
{
    m_context.bounds = gameBounds;
    m_player.setMovementBounds(m_context);
    m_enemies.reserve(MAX_ENEMIES);
    m_bullets.reserve(MAX_BULLETS);
    setUpSpawners();
}

void Game::setUpSpawners()
{
    m_classicEnemySpawner = new ClassicEnemySpawner(SpawnConfig{4.0f, m_context});
    m_fastEnemySpawner = new FastEnemySpawner(SpawnConfig{6.0f, m_context});
}

void Game::restart()
{
    m_state = GameState::Play;
    m_player.reset();
    m_enemyWaveManager.reset();
    
    destroyObjects();
    m_classicEnemySpawner->reset();
    m_fastEnemySpawner->reset();
}

void Game::update(float dt, const InputManager& input, const CollisionSystem& collision)
{
    if (m_state == GameState::GameOver)
    {
        if (input.isKeyJustPressed(toKey(GameAction::Restart)))
        {
            restart();
        }
        return;
    }

    m_player.handleInput(input);
    m_player.update(dt);

    handleShooting(input);
    handleSpawning(dt);

    updateEnemies(dt);
    updateBullets(dt);

    handleCollisions(collision);

    removeDeadObjects();
    m_enemyWaveManager.update(dt);
}

void Game::render(const Renderer& renderer) const
{
    renderEnemies(renderer);
    m_player.render(renderer);
    renderBullets(renderer);

    const std::string waveText = "Level " + std::to_string(m_enemyWaveManager.currentWave());
    m_textRenderer.draw(renderer, waveText, Position{10.0f, 10.0f}, Color{255, 255, 255});
}

void Game::updateEnemies(float dt)
{
    for (const auto& enemy : m_enemies)
    {
        enemy->update(dt);
    }
}

void Game::updateBullets(float dt)
{
    for (const auto& bullet : m_bullets)
    {
        bullet->update(dt);
    }
}

void Game::renderEnemies(const Renderer& renderer) const
{
    for (const auto& enemy : m_enemies)
    {
        enemy->render(renderer);
    }
}

void Game::renderBullets(const Renderer& renderer) const
{
    for (const auto& bullet : m_bullets)
    {
        bullet->render(renderer);
    }
}

void Game::handleSpawning(float dt)
{
    auto trySpawn = [&](SpawnerSystem* spawner)
    {
        if (!spawner || !m_enemyWaveManager.canSpawn())
            return;

        GameObject* object = spawner->spawnEntity(dt);
        if (object == nullptr)
            return;

        if (Enemy* enemy = dynamic_cast<Enemy*>(object))
        {
            if (m_enemies.size() >= MAX_ENEMIES)
            {
                delete enemy;
                return;
            }
            enemy->setTarget(m_player);
            m_enemies.push_back(enemy);
            m_enemyWaveManager.onEntitySpawned(enemy->getId());
        }
        else
        {
            delete object;
        }
    };

    trySpawn(m_classicEnemySpawner);
    trySpawn(m_fastEnemySpawner);
}

void Game::handleShooting(const InputManager& input)
{      
    if (input.isKeyJustPressed(toKey(GameAction::Shoot)))
    {
        if (m_bullets.size() >= MAX_BULLETS)
            return;

        Bullet* bullet = new Bullet(m_player.getPosition(),
                                    m_player.getShootVelocity(),
                                    m_player.getShootHeading(),
                                    m_context);
        m_bullets.push_back(bullet);
    }
}

void Game::handleCollisions(const CollisionSystem& collision)
{
    // Bullet vs Enemy
    for (auto* bullet : m_bullets)
    {
        if (!bullet->isAlive())
            continue;

        for (auto* enemy : m_enemies)
        {
            if (!enemy->isAlive())
                continue;

            if (collision.intersects(*bullet, *enemy))
            {
                bullet->destroy();
                enemy->destroy();
                break;
            }
        }
    }

    // Player vs Enemy
    for (auto* enemy : m_enemies)
    {
        if (!enemy->isAlive())
            continue;

        if (collision.intersects(m_player, *enemy))
        {
            m_player.destroy();
            enemy->destroy();
        }
    }
}

void Game::removeDeadObjects()
{
    if (!m_player.isAlive())
    {
        m_state = GameState::GameOver;
    }

    for (auto it = m_bullets.begin(); it != m_bullets.end(); )
    {
        if (!(*it)->isAlive())
        {
            delete *it;
            it = m_bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = m_enemies.begin(); it != m_enemies.end(); )
    {
        if (!(*it)->isAlive())
        {
            m_enemyWaveManager.onEntityDies((*it)->getId());
            delete *it;
            it = m_enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::destroyObjects()
{
    for (auto* enemy : m_enemies)
    {
        delete enemy;
    }

    for (auto* bullet : m_bullets)
    {
        delete bullet;
    }

    m_enemies.clear();
    m_bullets.clear();
}

void Game::destroySpawners()
{
    delete m_classicEnemySpawner;
    m_classicEnemySpawner = nullptr;

    delete m_fastEnemySpawner;
    m_fastEnemySpawner = nullptr;
}