#include <Player.h>

#include <Systems/InputManager.h>
#include <GameControls.h>

Player::Player() : GameObject("Player", Position{100.0f, 100.0f},
                              Appearance{ShapeType::Rectangle, Size{30, 30}, Color{0, 255, 0}})
{
    setVelocity(Velocity{250.0f, 250.0f});
}

void Player::update(float dt)
{
    setPosition(clampToBounds(move(getPosition(), dt), getAppearance().size));
}

void Player::handleInput(const InputManager& input)
{
    Heading tempHeading {0, 0};

    if (input.isKeyPressed(toKey(GameAction::MoveUp))) tempHeading.y -= 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveDown))) tempHeading.y += 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveLeft))) tempHeading.x -= 1.0f;
    if (input.isKeyPressed(toKey(GameAction::MoveRight))) tempHeading.x += 1.0f;

    setHeading(tempHeading);
}

void Player::reset()
{
    setPosition({100.0f, 100.0f});
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