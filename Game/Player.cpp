#include <Player.h>

#include <Systems/InputManager.h>
#include <GameControls.h>
#include <Core/VectorUtils.h>

Player::Player(Position spawnPoint)
                : GameObject("Player", spawnPoint, Appearance{ShapeType::Rectangle, Size{30, 30}, Color{0, 255, 0}}),
                  m_spawnPoint(spawnPoint)
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

    if (input.isKeyHeld(toKey(GameAction::MoveUp))) tempHeading.y -= 1.0f;
    if (input.isKeyHeld(toKey(GameAction::MoveDown))) tempHeading.y += 1.0f;
    if (input.isKeyHeld(toKey(GameAction::MoveLeft))) tempHeading.x -= 1.0f;
    if (input.isKeyHeld(toKey(GameAction::MoveRight))) tempHeading.x += 1.0f;

    setHeading(VectorUtils::normalize(tempHeading));
}

void Player::reset()
{
    setPosition(m_spawnPoint);
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