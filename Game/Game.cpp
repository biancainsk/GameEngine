#include "Game.h"
#include "../Engine/Core/Engine.h"
#include <bits/stdc++.h>

Game::Game()
{
    m_enemies.emplace_back();
    m_enemies.emplace_back();
}

void Game::update(float dt, const InputManager& input)
{
    m_player.update(dt, input);

    handleShooting(input);

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
            }
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
}