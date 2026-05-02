#ifndef IGAME_H
#define IGAME_H

class InputManager;
class Renderer;

class IGame
{
public:
    IGame() = default;
    virtual ~IGame() = default;

    virtual void initialize(int screenW, int screenH) = 0;
    virtual void update(float dt, const InputManager& input) = 0;
    virtual void render(Renderer& renderer) = 0;
};

#endif