#include "Player.h"

#include "../Engine/Core/Renderer.h"
#include "../Engine/Systems/InputManager.h"
#include "Bullet.h"

Player::Player() : GameObject(Position{100.0f, 100.0f},
                              Size{30.0f, 30.0f},
                              Velocity{250.0f, 250.0f},
                              ShapeType{ShapeType::Rectangle})
{}

void Player::update(float dt, const InputManager& input)
{
    if (input.isKeyPressed(SDL_SCANCODE_W))
    {
        // rect().y -= m_speed * dt;
        move(0, -getVelocity().y * dt);
    }

    if (input.isKeyPressed(SDL_SCANCODE_S))
    {
        // rect().y += m_speed * dt;
        move(0, getVelocity().y * dt);
    }

    if (input.isKeyPressed(SDL_SCANCODE_A))
    {
        // rect().x -= m_speed * dt;
        move(-getVelocity().x * dt, 0);
    }

    if (input.isKeyPressed(SDL_SCANCODE_D))
    {
        // rect().x += m_speed * dt;
        move(getVelocity().x * dt, 0);
    }
}

void Player::render(Renderer& renderer)
{
    renderer.drawRectangle(getPosition(), getSize());
}

Bullet Player::shoot() const
{
    return Bullet(getPosition(), getVelocity());
}