#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Core/Globals.h>
#include <SDL2/SDL.h>

class InputManager
{
public:
    void update();
    bool isKeyPressed(Key key) const;

private:
    const Uint8* m_keyboardState = nullptr;
};

#endif