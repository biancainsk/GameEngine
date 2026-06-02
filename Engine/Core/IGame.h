#ifndef IGAME_H
#define IGAME_H

struct Size;
class InputManager;
class CollisionSystem;
class Renderer;

class IGame
{
public:
    IGame() = default;
    virtual ~IGame() = default;

    virtual void initialize(const Size& gameBounds) = 0;
    virtual void update(float dt, const InputManager& input, const CollisionSystem& collision) = 0;
    virtual void render(const Renderer& renderer) const = 0;
};

#endif