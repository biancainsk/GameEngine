#include <Core/GameObject.h>

GameObject::GameObject(Position pos, Size size, Velocity velocity, ShapeType shape, Color color)
        : m_pos(pos), m_size(size), m_velocity(velocity), m_shape(shape), m_color(color)
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

ShapeType GameObject::getShape() const
{
    return m_shape;
}

void GameObject::setShape(ShapeType shape)
{
    m_shape = shape;
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

Color GameObject::getColor() const
{
    return m_color;
}

void GameObject::setColor(Color color)
{
    m_color = color;
}

void GameObject::move(float dx, float dy)
{
    m_pos.x += dx;
    m_pos.y += dy;
}

void GameObject::fixToWindowSize(int screenW, int screenH)
{
    if (m_pos.x - (m_size.width / 2) < 0)
    {
        m_pos.x = m_size.width / 2;
    }

    if (m_pos.x + m_size.width > screenW)
    {
        m_pos.x = screenW - m_size.width;
    }

    if (m_pos.y - (m_size.height / 2) < 0)
    {
        m_pos.y = m_size.height / 2;
    }

    if (m_pos.y + m_size.height > screenH)
    {
        m_pos.y = screenH - m_size.height;
    }
}

