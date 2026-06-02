#include <Enemy.h>

#include <Player.h>
#include <Core/Renderer.h>
#include <Core/VectorUtils.h>

// Enemy::Enemy() : GameObject(Position{200.0f, 200.0f},
//                             Velocity{20.0f, 20.0f},
//                             Heading{0.0f, 0.0f},
//                             ShapeType{ShapeType::Triangle},
//                             Size{30, 30},
//                             Color{255, 0, 0})
// {}

Enemy::Enemy(Position position, Velocity velocity)
                : GameObject(position, velocity,
                             Heading{0.0f, 0.0f},
                             ShapeType{ShapeType::Triangle},
                             Size{30, 30},
                             Color{255, 0, 0}),
                  m_target(position)
{}

// Enemy::Enemy(Position position) : m_target(position) {}

void Enemy::setTarget(Position target)
{
    m_target = target;
}

void Enemy::followTarget(float dt)
{
    Heading tempHeading = {m_target.x - getPosition().x,
                           m_target.y - getPosition().y};
    tempHeading = VectorUtils::normalize(tempHeading);
    setHeading(tempHeading);

    move(dt);
}

void Enemy::update(float dt)
{
    followTarget(dt);
}

void Enemy::render(const Renderer& renderer) const
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}