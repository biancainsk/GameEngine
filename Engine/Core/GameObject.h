#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Core/Globals.h>

class Renderer;

/**
 * @brief 
 * 
 */
class GameObject
{
public:

    GameObject(Position pos, Size size, Velocity velocity, ShapeType shape, Color color);

    /**
     * @brief Construct a new Game Object object
     * 
     */
    GameObject() = default;

    /**
     * @brief Destroy the Game Object object
     * 
     */
    virtual ~GameObject() = default;

    /**
     * @brief 
     * 
     * @param renderer 
     */
    virtual void render(Renderer& renderer) = 0;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isAlive() const;

    /**
     * @brief 
     * 
     */
    void destroy();

    ShapeType getShape() const;
    void setShape(ShapeType shape);

    Position getPosition() const;
    void setPosition(Position pos);

    Size getSize() const;
    void setSize(Size size);

    Velocity getVelocity() const;
    void setVelocity(Velocity velocity);

    Color getColor() const;
    void setColor(Color color);

    /**
     * @brief 
     * 
     * @param dx 
     * @param dy 
     */
    void move(float dx, float dy);

    void fixToWindowSize(int screenW, int screenH);

private:
    /**
     * @brief 
     * 
     */
    bool m_alive = true;

    Position m_pos;
    Size m_size;
    Velocity m_velocity;
    ShapeType m_shape;
    Color m_color;
};

#endif