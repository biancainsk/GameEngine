#ifndef GLOBALS_H
#define GLOBALS_H

#include <cmath>

/**
 * @brief Supported render shapes.
 */
enum class ShapeType
{
    Rectangle,
    Triangle
};

/**
 * @brief Objects' position with respect to the center of the object.
 */
struct Position
{
    float x = 0.0f;
    float y = 0.0f;
};

/**
 * @brief 2D velocity in units per second.
 */
struct Velocity
{
    float x = 0.0f;
    float y = 0.0f;
};

/**
 * @brief Unit direction vector (magnitude 1.0f).
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
 * @brief Width and height in pixels.
 */
struct Size
{
    int width = 0;
    int height = 0;
};

/**
 * @brief Color in rgba.
 */
struct Color
{
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    unsigned char a = 255;
};

/**
 * @brief Supported keys to produce actions.
 */
enum class Key
{
    W,
    A,
    S,
    D,
    Space,
    R
};

/**
 * @brief Shared game-wide state passed to game objects.
 */
struct GameContext
{
    Size bounds;
};

#endif