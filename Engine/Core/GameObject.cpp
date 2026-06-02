#include <Core/GameObject.h>
#include <cmath>

GameObject::GameObject(Position pos, Velocity velocity, Heading heading, ShapeType shape, Size size, Color color)
        : m_pos(pos), m_velocity(velocity), m_heading(heading), m_shape(shape), m_size(size), m_color(color)
{
}

void GameObject::initialize(const Size& gameBounds)
{
    m_gameBounds = gameBounds;
}

bool GameObject::isAlive() const
{
    return m_alive;
}

void GameObject::destroy()
{
    m_alive = false;
}

void GameObject::revive()
{
    m_alive = true;
}

Position GameObject::getPosition() const
{
    return m_pos;
}

void GameObject::setPosition(Position pos)
{
    m_pos = pos;
}

Velocity GameObject::getVelocity() const
{
    return m_velocity;
}

void GameObject::setVelocity(Velocity velocity)
{
    m_velocity = velocity;
}

Heading GameObject::getHeading() const
{
    return m_heading;
}

void GameObject::setHeading(Heading heading)
{
    m_heading = heading;
}

ShapeType GameObject::getShape() const
{
    return m_shape;
}

void GameObject::setShape(ShapeType shape)
{
    m_shape = shape;
}

Size GameObject::getSize() const
{
    return m_size;
}

void GameObject::setSize(Size size)
{
    m_size = size;
}

Color GameObject::getColor() const
{
    return m_color;
}

void GameObject::setColor(Color color)
{
    m_color = color;
}

void GameObject::move(float dt)
{
    m_pos.x += m_heading.x * std::abs(m_velocity.x) * dt;
    m_pos.y += m_heading.y * std::abs(m_velocity.y) * dt;
}

bool GameObject::exceedsBounds()
{
    return (m_pos.x - (m_size.width / 2) < 0) || (m_pos.x + m_size.width > m_gameBounds.width)
           || (m_pos.y - (m_size.height / 2) < 0) || (m_pos.y + m_size.height > m_gameBounds.height);
    // if (m_pos.x - (m_size.width / 2) < 0)
    // {
    //     m_pos.x = m_size.width / 2;
    // }

    // if (m_pos.x + m_size.width > screenW)
    // {
    //     m_pos.x = screenW - m_size.width;
    // }

    // if (m_pos.y - (m_size.height / 2) < 0)
    // {
    //     m_pos.y = m_size.height / 2;
    // }

    // if (m_pos.y + m_size.height > screenH)
    // {
    //     m_pos.y = screenH - m_size.height;
    // }
}

Size GameObject::getGameBounds() const
{
    return m_gameBounds;
}