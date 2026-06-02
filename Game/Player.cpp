#include <Player.h>

#include <Systems/InputManager.h>
#include <Core/Renderer.h>
#include <Core/Globals.h>
#include <Core/VectorUtils.h>
#include "GameControls.h"

Player::Player() : GameObject(Position{100.0f, 100.0f},
                              Velocity{250.0f, 250.0f},
                              Heading{0.0f, 0.0f},
                              ShapeType{ShapeType::Rectangle},
                              Size{30, 30},
                              Color{0, 255, 0})
{}

void Player::update(float dt)
{
    if (m_allowMove)
        move(dt);

    if (exceedsBounds())
    {
        clampToBounds(getGameBounds());
    }
}

void Player::render(const Renderer& renderer) const
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}

void Player::reset()
{
    setPosition({100.0f, 100.0f});
    setVelocity({250.0f, 250.0f});
    setHeading({0.0f, 0.0f});
    revive();
}

void Player::handleInput(const InputManager& input)
{
    Heading tempHeading {0, 0};

    if (input.isKeyPressed(toKey(GameAction::MoveUp))) tempHeading.y -= 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveDown))) tempHeading.y += 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveLeft))) tempHeading.x -= 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveRight))) tempHeading.x += 1.0f;

    if (tempHeading.x != 0.0f || tempHeading.y != 0.0f)
    {
        tempHeading = VectorUtils::normalize(tempHeading);
        setHeading(tempHeading);
        m_allowMove = true;
    }
    else
    {
        m_allowMove = false;
    }
}

Velocity Player::getShootVelocity() const
{
    return {getVelocity().x * 2, getVelocity().y * 2};
}

Heading Player::getShootHeading() const
{
    return (getHeading() != Heading{0.0f, 0.0f}) ? getHeading() : Heading{1.0f, 0.0f};
}

void Player::clampToBounds(const Size& gameBounds)
{
    const float objHalfWidth = getSize().width / 2.0f;
    const float objHalfHeight = getSize().height / 2.0f;

    const float rightLimit = static_cast<float>(gameBounds.width - getSize().width);
    const float bottomLimit = static_cast<float>(gameBounds.height - getSize().height);

    Position pos = getPosition();

    if (pos.x < objHalfWidth)
    {
        pos.x = objHalfWidth;
    }

    if (pos.x > rightLimit)
    {
        pos.x = rightLimit;
    }

    if (pos.y < objHalfHeight)
    {
        pos.y = objHalfHeight;
    }

    if (pos.y > bottomLimit)
    {
        pos.y = bottomLimit;
    }

    setPosition(pos);
}