#include "GameObject.h"

GameObject::GameObject(Position pos, Size size, Velocity velocity, ShapeType shape)
        : m_pos(pos), m_size(size), m_velocity(velocity), m_shape(shape)
{
}

bool GameObject::isAlive() const
{
    return m_alive;
}

void GameObject::destroy()
{
    m_alive = false;
}

Position GameObject::getPosition() const
{
    return m_pos;
}

void GameObject::setPosition(Position pos)
{
    m_pos = pos;
}

Size GameObject::getSize() const
{
    return m_size;
}

void GameObject::setSize(Size size)
{
    m_size = size;
}

Velocity GameObject::getVelocity() const
{
    return m_velocity;
}

void GameObject::setVelocity(Velocity velocity)
{
    m_velocity = velocity;
}

ShapeType GameObject::getShape() const
{
    return m_shape;
}

void GameObject::setShape(ShapeType shape)
{
    m_shape = shape;
}

void GameObject::move(float dx, float dy)
{
    m_pos.x += dx;
    m_pos.y += dy;
}

