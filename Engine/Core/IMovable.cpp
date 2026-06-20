#include <Core/IMovable.h>

Velocity IMovable::getVelocity() const
{
    return m_velocity;
}

void IMovable::setVelocity(Velocity velocity)
{
    m_velocity = velocity;
}

Heading IMovable::getHeading() const
{
    return m_heading;
}

void IMovable::setHeading(Heading heading)
{
    m_heading = heading;
}

void IMovable::setMovementBounds(const GameContext& context)
{
    m_context = context;
}

Position IMovable::move(Position position, float dt) const
{
    position.x += m_heading.x * m_velocity.x * dt;
    position.y += m_heading.y * m_velocity.y * dt;
    return position;
}

bool IMovable::exceedsBounds(Position position, Size size) const
{
    const float halfW = size.width  / 2.0f;
    const float halfH = size.height / 2.0f;

    return (position.x - halfW < 0) ||
           (position.x + halfW > m_context.bounds.width) ||
           (position.y - halfH < 0) ||
           (position.y + halfH > m_context.bounds.height);
}

Position IMovable::clampToBounds(Position position, Size size) const
{
    const float halfW = size.width  / 2.0f;
    const float halfH = size.height / 2.0f;

    if (position.x - halfW < 0)
        position.x = halfW;
    if (position.x + halfW > m_context.bounds.width)
        position.x = m_context.bounds.width - halfW;
    if (position.y - halfH < 0)
        position.y = halfH;
    if (position.y + halfH > m_context.bounds.height)
        position.y = m_context.bounds.height - halfH;

    return position;
}