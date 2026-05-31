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

    GameObject(Position pos, Velocity velocity, Heading heading, ShapeType shape, Size size, Color color);

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
    virtual void render(const Renderer& renderer) const = 0;

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

    void revive();

    Position getPosition() const;
    void setPosition(Position pos);

    Velocity getVelocity() const;
    void setVelocity(Velocity velocity);

    Heading getHeading() const;
    void setHeading(Heading heading);

    ShapeType getShape() const;
    void setShape(ShapeType shape);

    Size getSize() const;
    void setSize(Size size);

    Color getColor() const;
    void setColor(Color color);

    /**
     * @brief position = position + velocity * time
     * 
     * @param dx 
     * @param dy 
     */
    void move(float dt);

    bool exceedsBounds(const Size& gameSize);

private:
    /**
     * @brief 
     * 
     */
    bool m_alive = true;

    Position m_pos;
    Velocity m_velocity;
    Heading m_heading;
    ShapeType m_shape;
    Size m_size;
    Color m_color;
};

#endif