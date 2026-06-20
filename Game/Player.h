#ifndef PLAYER_H
#define PLAYER_H

#include <Core/GameObject.h>
#include <Core/IMovable.h>

class InputManager;

class Player : public GameObject, public IMovable
{
public:
    Player(Position spawnPoint = {100.0f, 100.0f});

    void update(float dt) override;
    void handleInput(const InputManager& input);
    void reset();

    Velocity getShootVelocity() const;
    Heading getShootHeading() const;

private:
    Position m_spawnPoint;
};

#endif