#include <Game.h>
#include <Systems/InputManager.h>
#include <Systems/CollisionSystem.h>
#include <Core/Renderer.h>

#include <algorithm>

void Game::initialize(int screenW, int screenH)
{
    m_screenWidth = screenW;
    m_screenHeight = screenH;

    m_enemySpawner = EnemySpawner(screenW, screenH);
}

void Game::update(float dt, const InputManager& input, const CollisionSystem& collision)
{
    if (m_state == GameState::GameOver)
    {
        if (input.isKeyPressed(SDL_SCANCODE_R))
        {
            restart();
        }

        return;
    }

    m_player.update(dt, input);
    // m_player.fixToWindowSize(m_screenWidth, m_screenHeight);
    handleShooting(input);

    if (m_enemySpawner.shouldSpawn(dt))
    {
        m_enemies.push_back(m_enemySpawner.spawnEnemy());
    }

    updateEnemies(dt);
    updateBullets(dt);

    handleCollisions(collision);
    removeDeadObjects();
}

void Game::render(const Renderer& renderer) const
{
    m_player.render(renderer);

    for (const Enemy& enemy : m_enemies)
    {
        enemy.render(renderer);
    }

    for (const Bullet& bullet : m_bullets)
    {
        bullet.render(renderer);
    }
}

void Game::restart()
{
    m_state = GameState::Play;

    m_player = Player();
    m_enemies.clear();
    m_bullets.clear();

    m_enemySpawner = EnemySpawner(m_screenWidth, m_screenHeight);
    m_spaceWasPressed = false;
}

void Game::handleShooting(const InputManager& input)
{      
    const bool spaceIsPressed = input.isKeyPressed(SDL_SCANCODE_SPACE);

    if (spaceIsPressed && !m_spaceWasPressed)
    {
        m_bullets.emplace_back(m_player.getPosition(),
                               m_player.getShootVelocity(),
                               m_player.getShootHeading()
                               );
    }

    m_spaceWasPressed = spaceIsPressed;
}

void Game::updateEnemies(float dt)
{
    for (Enemy& enemy : m_enemies)
    {
        enemy.update(dt, m_player);
    }
}

void Game::updateBullets(float dt)
{
    for (Bullet& bullet : m_bullets)
    {
        bullet.update(dt);
    }
}

void Game::handleCollisions(const CollisionSystem& collision)
{
    for (Bullet& bullet : m_bullets)
    {
        for (Enemy& enemy : m_enemies)
        {
            bool isCollision = collision.intersects(bullet, enemy);

            if(isCollision)
            {
                bullet.destroy();
                enemy.destroy();
                break;
            }
        }
        // Add logic if the bullet exits the window to be cleared up
        if (bullet.getPosition().x > m_screenWidth || bullet.getPosition().x < 0
            || bullet.getPosition().y > m_screenHeight || bullet.getPosition().y < 0)
        {
            bullet.destroy();
        }
    }

    // Add logic if the enemy catches the player to end game
    for (Enemy& enemy : m_enemies)
    {
        bool isCollision = collision.intersects(m_player, enemy);
        if(isCollision)
        {
            m_player.destroy();
            break;
        }
    }
}

void Game::removeDeadObjects()
{
    if (!m_player.isAlive())
    {
        m_state = GameState::GameOver;
    }

    m_bullets.erase(std::remove_if(m_bullets.begin(), m_bullets.end(), [](const Bullet& bullet)
    {
        return !bullet.isAlive();
    }), m_bullets.end());

    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(), [](const Enemy& enemy)
    {
        return !enemy.isAlive();
    }), m_enemies.end());
}