#include <Game.h>
#include <Systems/InputManager.h>
#include <Systems/CollisionSystem.h>
#include <Core/Renderer.h>
#include <GameControls.h>

#include <Bullet.h>
#include <Enemy.h>
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
    m_gameBounds.initialize(gameBounds);
    m_player.initialize(m_gameBounds);
    setUpSpawners();
}

void Game::setUpSpawners()
{
    m_classicEnemySpawner = new ClassicEnemySpawner(SpawnConfig{4.0f, m_gameBounds});
    m_fastEnemySpawner = new FastEnemySpawner(SpawnConfig{6.0f, m_gameBounds});
}

void Game::restart()
{
    m_state = GameState::Play;

    m_player.reset();
    destroyObjects();
    destroySpawners();
    setUpSpawners();
}

void Game::update(float dt, const InputManager& input, const CollisionSystem& collision)
{
    if (m_state == GameState::GameOver)
    {
        if (input.isKeyPressed(toKey(GameAction::Restart)))
        {
            restart();
        }

        return;
    }

    m_player.handleInput(input);
    m_player.update(dt);
    handleShooting(input);

    handleSpawning(dt);

    updateEnemyTargets();
    updateObjects(dt);

    handleCollisions(collision);
    removeDeadObjects();
}

void Game::render(const Renderer& renderer) const
{
    m_player.render(renderer);
    renderObjects(renderer);
}

void Game::updateObjects(float dt)
{
    for (GameObject* object : m_objects)
    {
        if (object != nullptr)
        {
            object->update(dt);
        }
    }
}

void Game::renderObjects(const Renderer& renderer) const
{
    for (GameObject* object : m_objects)
    {
        if (object != nullptr)
        {
            object->render(renderer);
        }
    }
}

void Game::updateEnemyTargets()
{
    for (const auto& object : m_objects)
    {
        if (object == nullptr) continue;
 
        Enemy* enemy = dynamic_cast<Enemy*>(object);
        if (enemy != nullptr)
        {
            enemy->setTarget(m_player.getPosition());
        }
    }
}

void Game::handleSpawning(float dt)
{
    auto trySpawn = [&](SpawnerSystem* spawner)
    {
        if (!spawner || !spawner->shouldSpawn(dt))
            return;

        GameObject* object = spawner->spawnEntity(dt);
        if (object == nullptr)
            return;

        Enemy* enemy = dynamic_cast<Enemy*>(object);
        if (enemy != nullptr)
        {
            enemy->setTarget(m_player.getPosition());
        }

        m_objects.push_back(object);
    };

    trySpawn(m_classicEnemySpawner);
    trySpawn(m_fastEnemySpawner);
}

void Game::handleShooting(const InputManager& input)
{      
    if (input.isKeyPressed(toKey(GameAction::Shoot)))
    {
        GameObject* bullet = new Bullet(m_player.getPosition(),
                                        m_player.getShootVelocity(),
                                        m_player.getShootHeading()
                                       );
        bullet->initialize(m_gameBounds);
        m_objects.push_back(bullet);
    }
}

void Game::handleCollisions(const CollisionSystem& collision)
{
    for (const auto& firstObject : m_objects)
    {
        if (!firstObject || !firstObject->isAlive())
            continue;
        
        Bullet* bullet = dynamic_cast<Bullet*>(firstObject);
        if (bullet == nullptr)
            continue;

        for (const auto& secondObject : m_objects)
        {
            if (!secondObject || !secondObject->isAlive())
                continue;

            Enemy* enemy = dynamic_cast<Enemy*>(secondObject);
            if (enemy == nullptr)
                continue;

            if (collision.intersects(*bullet, *enemy))
            {
                bullet->destroy();
                enemy->destroy();
                break;
            }
        }
    }

    for (const auto& object : m_objects)
    {
        if (!object || !object->isAlive())
            continue;

        Enemy* enemy = dynamic_cast<Enemy*>(object);
        if (enemy == nullptr)
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

    for (auto it = m_objects.begin(); it != m_objects.end();)
    {
        GameObject* object = *it;

        if ((object == nullptr) || (!object->isAlive()))
        {
            delete object;
            it = m_objects.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::destroyObjects()
{
    for (GameObject* object : m_objects)
    {
        delete object;
    }

    m_objects.clear();
}

void Game::destroySpawners()
{
    delete m_classicEnemySpawner;
    m_classicEnemySpawner = nullptr;

    delete m_fastEnemySpawner;
    m_fastEnemySpawner = nullptr;
}