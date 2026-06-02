#ifndef PLAYER_H
#define PLAYER_H

#include <Core/GameObject.h>

class InputManager;
class Renderer;
struct Size;

class Player : public GameObject
{
public:
    Player();

    void update(float dt) override;
    void render(const Renderer& renderer) const override;

    void handleInput(const InputManager& input);
    void reset();

    Velocity getShootVelocity() const;
    Heading getShootHeading() const;
    void clampToBounds(const Size& gameBounds);

private:
    bool m_allowMove = false;
};

#endif