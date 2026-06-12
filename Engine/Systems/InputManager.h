#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Core/Globals.h>
#include <SDL2/SDL.h>
#include <vector>

class InputManager
{
public:
    void update();
    bool isKeyPressed(Key key) const;
    bool isKeyReleased(Key key) const;

private:
    std::vector<Uint8> m_keyboardCurrentState;
    std::vector<Uint8> m_keyboardPreviousState;
};

#endif