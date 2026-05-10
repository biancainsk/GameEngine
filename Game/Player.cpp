#include <Player.h>

#include <Systems/InputManager.h>
#include <Core/Renderer.h>
#include <Bullet.h>

Player::Player() : GameObject(Position{100.0f, 100.0f},
                              Size{30.0f, 30.0f},
                              Velocity{250.0f, 250.0f},
                              ShapeType{ShapeType::Rectangle},
                              Color{0, 255, 0})
{}

void Player::update(float dt, const InputManager& input)
{
    Velocity direction {0.0f, 0.0f};

    if (input.isKeyPressed(SDL_SCANCODE_W))
    {
        move(0, -getVelocity().y * dt);
        direction.y -= 1.0f;
    }

    if (input.isKeyPressed(SDL_SCANCODE_S))
    {
        move(0, getVelocity().y * dt);
        direction.y += 1.0f;
    }

    if (input.isKeyPressed(SDL_SCANCODE_A))
    {
        move(-getVelocity().x * dt, 0);
        direction.x -= 1.0f;
    }

    if (input.isKeyPressed(SDL_SCANCODE_D))
    {
        move(getVelocity().x * dt, 0);
        direction.x += 1.0f;
    }

    if (direction.x != 0.0f || direction.y != 0.0f)
    {
        m_trajectory = direction;
    }
}

void Player::render(Renderer& renderer)
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}

Bullet Player::shoot() const
{
    Velocity bulletVelocity = {m_trajectory.x * 500.0f, m_trajectory.y * 500.0f};
    return Bullet(getPosition(), bulletVelocity);
}