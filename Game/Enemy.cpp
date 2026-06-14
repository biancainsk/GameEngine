#include <Enemy.h>

Enemy::Enemy(const std::string& name, Position position,
             Velocity velocity, Appearance appearance, const GameContext& context)
                : GameObject(name, position, appearance)
{
    setVelocity(velocity);
    setMovementBounds(context);
}

void Enemy::update(float dt)
{
    behave();
    setPosition(move(getPosition(), dt));
}

void Enemy::behave()
{
    setHeading(headingToTarget(getPosition()));
}