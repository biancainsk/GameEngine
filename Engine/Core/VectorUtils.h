#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <Core/Globals.h>
#include <cmath>

namespace VectorUtils
{
    inline Heading normalize(Heading h)
    {
        float length = std::sqrt(h.x * h.x + h.y * h.y);

        if (length > 1e-6f)
        {
            h.x /= length;
            h.y /= length;
        }
        return h;
    }
}

#endif