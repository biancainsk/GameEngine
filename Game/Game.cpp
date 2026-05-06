#include <Game.h>
#include <Systems/InputManager.h>
#include <Core/Renderer.h>

#include <bits/stdc++.h>

void Game::initialize(int screenW, int screenH)
{
    m_enemySpawner = EnemySpawner(screenW, screenH);
}

void Game::update(float dt, const InputManager& input)
{
    if (m_state == GameState::GameOver)
    {
        if (input.isKeyPressed(SDL_SCANCODE_R))
        {
            reset();
        }

        return;
    }
    m_player.update(dt, input);
    handleShooting(input);

    if (m_enemySpawner.shouldSpawn(dt))
    {
        m_enemies.push_back(m_enemySpawner.spawnEnemy());
    }

    updateEnemies(dt);
    updateBullets(dt);

    handleCollisions();
    removeDeadObjects();
}

void Game::render(Renderer& renderer)
{
    m_player.render(renderer);

    for (Enemy& enemy : m_enemies)
    {
        enemy.render(renderer);
    }

    for (Bullet& bullet : m_bullets)
    {
        bullet.render(renderer);
    }
}

void Game::reset()
{
    m_state = GameState::Play;
    
    m_player = Player();
    m_enemies.clear();
    m_bullets.clear();
}

void Game::handleShooting(const InputManager& input)
{
    bool spaceIsPressed = input.isKeyPressed(SDL_SCANCODE_SPACE);

    if (spaceIsPressed && !m_spaceWasPressed)
    {
        m_bullets.push_back(m_player.shoot());
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

void Game::handleCollisions()
{
    for (Bullet& bullet : m_bullets)
    {
        for (Enemy& enemy : m_enemies)
        {
            const Position& bulletPos = bullet.getPosition();
            const Position& enemyPos = enemy.getPosition();
            const Size& bulletSize = bullet.getSize();
            const Size& enemySize = enemy.getSize();

            bool collision = m_collision.intersects(bulletPos, enemyPos, bulletSize, enemySize);

            if(collision)
            {
                bullet.destroy();
                enemy.destroy();
                return;
            }
        }
        // Add logic if the bullet exits the window to be cleared up
        if (false)
        {
            bullet.destroy();
        }
    }

    // Add logic if the enemy catches the player to end game
    for (Enemy& enemy : m_enemies)
    {
        const Position& playerPos = m_player.getPosition();
        const Position& enemyPos = enemy.getPosition();
        const Size& playerSize = m_player.getSize();
        const Size& enemySize = enemy.getSize();

        bool collision = m_collision.intersects(playerPos, enemyPos, playerSize, enemySize);
        if(collision)
        {
            m_player.destroy();
            return;
        }
    }
}

void Game::removeDeadObjects()
{
    m_bullets.erase(std::remove_if(m_bullets.begin(), m_bullets.end(), [](const Bullet& bullet)
    {
        return !bullet.isAlive();
    }), m_bullets.end());

    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(), [](const Enemy& enemy)
    {
        return !enemy.isAlive();
    }), m_enemies.end());

    if (!m_player.isAlive())
    {
        m_state = GameState::GameOver;
    }
}