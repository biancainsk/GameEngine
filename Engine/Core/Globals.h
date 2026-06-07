#ifndef GLOBALS_H
#define GLOBALS_H

#include <cmath>

/**
 * @brief 
 * 
 */
enum class ShapeType
{
    Rectangle,
    Triangle
};

/**
 * @brief With respect to the center of the object.
 * 
 */
struct Position
{
    float x = 0.0f;
    float y = 0.0f;
};

/**
 * @brief 
 * 
 */
struct Velocity
{
    float x = 0.0f;
    float y = 0.0f;
};

/**
 * @brief This will be populated with the standard unit direction vector (1.0f unit).
 * 
 */
struct Heading
{
    float x = 0.0f;
    float y = 0.0f;

    bool operator==(const Heading& other) const
    {
        constexpr float eps = 1e-6f;
        return std::abs(x - other.x) < eps && 
               std::abs(y - other.y) < eps;
    }

    bool operator!=(const Heading& other) const
    {
        return !(*this == other);
    }
};

/**
 * @brief 
 * 
 */
struct Size
{
    int width = 0;
    int height = 0;
};

struct Color
{
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    unsigned char a = 255;
};

enum class Key
{
    W,
    A,
    S,
    D,
    Space,
    R
};

struct GameContext
{
    Size bounds;
};

#endif