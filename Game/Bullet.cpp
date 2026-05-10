#include <Bullet.h>
#include <Core/Renderer.h>

Bullet::Bullet() : GameObject(Position{100.0f, 100.0f},
                              Size{10.0f, 5.0f},
                              Velocity{500.0f, 500.0f},
                              ShapeType{ShapeType::Rectangle},
                              Color{0, 255, 0})
{}

Bullet::Bullet(Position pos, Velocity velocity)
            : GameObject(pos, Size{10.0f, 5.0f},
                         velocity, ShapeType{ShapeType::Rectangle},
                         Color{0, 255, 0})
{}

void Bullet::update(float dt)
{
    move(getVelocity().x * dt, getVelocity().y * dt);
}

void Bullet::render(Renderer& renderer)
{
    renderer.drawEntity(getPosition(), getSize(), getShape(), getColor());
}