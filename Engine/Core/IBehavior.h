#ifndef IBEHAVIOR_H
#define IBEHAVIOR_H

#include <Core/Globals.h>

class IBehavior
{
public:
    IBehavior() = default;
    virtual ~IBehavior() = default;
    IBehavior(const IBehavior&) = delete;
    IBehavior& operator=(const IBehavior&) = delete;

    virtual void behave() = 0;
    void setTarget(Position t);

protected:
    Heading headingToTarget(Position startPosition) const;

private:
    Position m_target;
};

#endif