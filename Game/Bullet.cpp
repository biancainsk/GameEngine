#include <Bullet.h>
#include <Core/Renderer.h>

Bullet::Bullet() : GameObject(Position{100.0f, 100.0f},
                              Velocity{500.0f, 500.0f},
                              Heading{0.0f, 0.0f},
                              ShapeType{ShapeType::Rectangle},
                              Size{10.0f, 5.0f},
                              Color{0, 255, 0})
{}

Bullet::Bullet(Position pos, Velocity velocity, Heading heading)
            : GameObject(pos, velocity, heading,
                         ShapeType{ShapeType::Rectangle}, Size{10.0f, 5.0f},
                         Color{0, 255, 0})
{}

void Bullet::update(float dt, const Size& gameBounds)
{
    move(dt);
    
    if (exceedsBounds(gameBounds))
    {
        destroy();
    }
}

void Bullet::render(const Renderer& renderer) const
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}