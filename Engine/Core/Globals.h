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
struct Size
{
    Size(float width = 0.0f, float height = 0.0f) : width(width), height(height) {}
    float width;
    float height;
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

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a = 255;
};

#endif