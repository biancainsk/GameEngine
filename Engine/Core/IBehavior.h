#ifndef IBEHAVIOR_H
#define IBEHAVIOR_H

#include <Core/Globals.h>

class GameObject;

class IBehavior
{
public:
    IBehavior() = default;
    virtual ~IBehavior() = default;
    IBehavior(const IBehavior&) = delete;
    IBehavior& operator=(const IBehavior&) = delete;

    virtual void behave() = 0;
    void setTarget(const GameObject& target);

protected:
    Heading headingToTarget(Position startPosition) const;

private:
    const GameObject* m_target = nullptr;
};

#endif