#include <Player.h>

#include <Systems/InputManager.h>
#include <Core/Renderer.h>
#include <Bullet.h>
#include <Core/VectorUtils.h>

Player::Player() : GameObject(Position{100.0f, 100.0f},
                              Velocity{250.0f, 250.0f},
                              Heading{0.0f, 0.0f},
                              ShapeType{ShapeType::Rectangle},
                              Size{30.0f, 30.0f},
                              Color{0, 255, 0})
{}

void Player::update(float dt, const InputManager& input)
{
    Heading tempHeading {0, 0};

    if (input.isKeyPressed(SDL_SCANCODE_W)) tempHeading.y -= 1.0f;
    if (input.isKeyPressed(SDL_SCANCODE_S)) tempHeading.y += 1.0f;
    if (input.isKeyPressed(SDL_SCANCODE_A)) tempHeading.x -= 1.0f;
    if (input.isKeyPressed(SDL_SCANCODE_D)) tempHeading.x += 1.0f;

    if (tempHeading.x != 0.0f || tempHeading.y != 0.0f)
    {
        tempHeading = VectorUtils::normalize(tempHeading);
        setHeading(tempHeading);

        move(dt);
    }
}

void Player::render(const Renderer& renderer) const
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}

Velocity Player::getShootVelocity() const
{
    return {getVelocity().x * 2, getVelocity().y * 2};
}

Heading Player::getShootHeading() const
{
    return (getHeading() != Heading{0.0f, 0.0f}) ? getHeading() : Heading{1.0f, 0.0f};
}

// Bullet Player::shoot() const
// {
//     Heading bulletHeading = (getHeading() != Heading{0.0f, 0.0f}) ? getHeading() : Heading{1.0f, 0.0f};
//     Velocity bulletVelocity = {getVelocity().x * 2, getVelocity().y * 2};
//     return Bullet(getPosition(), bulletVelocity, bulletHeading);
// }