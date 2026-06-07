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
    Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x;
    float y;
};

/**
 * @brief 
 * 
 */
struct Velocity
{
    Velocity(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x;
    float y;
};

/**
 * @brief This will be populated with the standard unit direction vector (1.0f unit).
 * 
 */
struct Heading
{
    Heading(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x;
    float y;

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
    Size(int width = 0, int height = 0) : width(width), height(height) {}
    int width;
    int height;
};

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
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