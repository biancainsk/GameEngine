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
                              Size{30.0f, 30.0f},
                              Color{0, 255, 0})
{}

void Player::update(float dt, const InputManager& input, const Size& gameBounds)
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

        move(dt);
    }

    if (exceedsBounds(gameBounds))
    {
        clampToBounds(gameBounds);
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
    if (getPosition().x - (getSize().width / 2) < 0)
    {
        setPosition(Position{getSize().width / 2, getPosition().y});
    }

    if (getPosition().x + getSize().width > gameBounds.width)
    {
        setPosition(Position{gameBounds.width - getSize().width, getPosition().y});
    }

    if (getPosition().y - (getSize().height / 2) < 0)
    {
        setPosition(Position{getPosition().x, getSize().height / 2});
    }

    if (getPosition().y + getSize().height > gameBounds.height)
    {
        setPosition(Position{getPosition().x, gameBounds.height - getSize().height});
    }
}