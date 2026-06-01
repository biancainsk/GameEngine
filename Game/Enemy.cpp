#include <Enemy.h>

#include <Player.h>
#include <Core/Renderer.h>
#include <Core/VectorUtils.h>

Enemy::Enemy() : GameObject(Position{200.0f, 200.0f},
                            Velocity{20.0f, 20.0f},
                            Heading{0.0f, 0.0f},
                            ShapeType{ShapeType::Triangle},
                            Size{30, 30},
                            Color{255, 0, 0})
{}

Enemy::Enemy(Position pos) : GameObject(pos, Velocity{20.0f, 20.0f},
                             Heading{0.0f, 0.0f},
                             ShapeType{ShapeType::Triangle},
                             Size{30, 30},
                             Color{255, 0, 0})
{}

void Enemy::update(float dt, const Player& player)
{
    Heading tempHeading = {player.getPosition().x - getPosition().x,
                           player.getPosition().y - getPosition().y};

    tempHeading = VectorUtils::normalize(tempHeading);
    setHeading(tempHeading);

    move(dt);
}

void Enemy::render(const Renderer& renderer) const
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}