#include <Core/IBehavior.h>
#include <Core/VectorUtils.h>

void IBehavior::setTarget(Position t)
{
    m_target = t;
}

Heading IBehavior::headingToTarget(Position startPosition) const
{
    Heading tempHeading = {m_target.x - startPosition.x,
                           m_target.y - startPosition.y};
    return VectorUtils::normalize(tempHeading);
}