#ifndef GLOBALS_H
#define GLOBALS_H

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
 * @brief 
 * 
 */
struct Position
{
    Position(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    float x;   // Center X
    float y;   // Center Y
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
    Heading(float x = 0, float y = 0) : x(x), y(y) {}
    float x;
    float y;

    bool operator==(const Heading& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Heading& other) const
    {
        return x != other.x || y != other.y;
    }
};

/**
 * @brief 
 * 
 */
struct Size
{
    Size(float width = 0.0f, float height = 0.0f) : width(width), height(height) {}
    void initialize(float newWidth, float newHeight) { width = newWidth; height = newHeight;}
    float width;
    float height;
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

#endif