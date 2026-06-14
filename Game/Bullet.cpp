#include <Bullet.h>

Bullet::Bullet(Position position, Velocity velocity, Heading heading, const GameContext& context)
            : GameObject("Bullet", position,
                         Appearance{ShapeType::Rectangle, Size{10, 5}, Color{0, 255, 0}})
{
    setVelocity(velocity);
    setHeading(heading);
    setMovementBounds(context);
}

void Bullet::update(float dt)
{
    setPosition(move(getPosition(), dt));
    
    if (exceedsBounds(getPosition(), getAppearance().size))
        destroy();
}