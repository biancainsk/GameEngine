#ifndef IMOVABLE_H
#define IMOVABLE_H

#include <Core/Globals.h>

class IMovable
{
public:
    IMovable() = default;
    virtual ~IMovable() = default;
    IMovable(const IMovable&) = delete;
    IMovable& operator=(const IMovable&) = delete;

    Velocity getVelocity() const;
    void setVelocity(Velocity velocity);

    Heading getHeading() const;
    void setHeading(Heading heading);

    Position move(Position position, float dt) const;

    void setMovementBounds(const GameContext& context);
    bool exceedsBounds(Position position, Size size) const;
    Position clampToBounds(Position position, Size size) const;

private:
    Velocity m_velocity;
    Heading m_heading;
    GameContext m_context;
};

#endif