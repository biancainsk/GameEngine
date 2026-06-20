#include <Core/IBehavior.h>
#include <Core/VectorUtils.h>
#include <Core/GameObject.h>

void IBehavior::setTarget(const GameObject& target)
{
    m_target = &target;
}

Heading IBehavior::headingToTarget(Position startPosition) const
{
    // No target -> No direction
    if (!m_target)
    {
        return Heading{};
    }

    Heading tempHeading = {m_target->getPosition().x - startPosition.x,
                           m_target->getPosition().y - startPosition.y};

    return VectorUtils::normalize(tempHeading);
}