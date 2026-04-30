#include "Enemy.h"

#include "Player.h"
#include "../Engine/Core/Renderer.h"

Enemy::Enemy() : GameObject(Position{200.0f, 200.0f},
                            Size{30.0f, 30.0f},
                            Velocity{20.0f, 20.0f},
                            ShapeType{ShapeType::Triangle})
{}

void Enemy::update(float dt, const Player& player)
{
    if (getPosition().x < player.getPosition().x)
    {
        move(getVelocity().x * dt, 0);
    }
    else if (getPosition().x > player.getPosition().x)
    {
        move(-getVelocity().x * dt, 0);
    }

    if (getPosition().y < player.getPosition().y)
    {
        move(0, getVelocity().y * dt);
    }
    else if (getPosition().y > player.getPosition().y)
    {
        move(0, -getVelocity().y * dt);
    }
}

void Enemy::render(Renderer& renderer)
{
    renderer.drawTriangle(getPosition(), getSize());
}