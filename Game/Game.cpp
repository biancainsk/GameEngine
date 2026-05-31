#include <Game.h>
#include <Systems/InputManager.h>
#include <Systems/CollisionSystem.h>
#include <Core/Renderer.h>
#include "GameControls.h"

#include <algorithm>

void Game::initialize(int screenW, int screenH)
{
    m_gameBounds.initialize(screenW, screenH);
    m_enemySpawner.initialize(m_gameBounds);

    restart();
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

    m_player.update(dt, input, m_gameBounds);
    handleShooting(input);

    if (m_enemySpawner.shouldSpawn(dt))
    {
        m_enemies.emplace_back(m_enemySpawner.spawnEnemyPosition());
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

    m_player.reset();
    m_enemies.clear();
    m_bullets.clear();

    m_enemySpawner.reset();
}

void Game::handleShooting(const InputManager& input)
{      
    if (input.isKeyPressed(toKey(GameAction::Shoot)))
    {
        m_bullets.emplace_back(m_player.getPosition(),
                               m_player.getShootVelocity(),
                               m_player.getShootHeading()
                               );
    }
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
        bullet.update(dt, m_gameBounds);
    }
}

void Game::handleCollisions(const CollisionSystem& collision)
{
    if (!m_player.isAlive())
    {
        return;
    }

    for (Bullet& bullet : m_bullets)
    {
        if (!bullet.isAlive())
        {
            continue;
        }

        for (Enemy& enemy : m_enemies)
        {
            if (!enemy.isAlive())
            {
                continue;
            }

            if (collision.intersects(bullet, enemy))
            {
                bullet.destroy();
                enemy.destroy();
                break;
            }
        }
    }

    // Add logic if the enemy catches the player to end game
    for (Enemy& enemy : m_enemies)
    {
        if (!enemy.isAlive())
        {
            continue;
        }

        if (collision.intersects(m_player, enemy))
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