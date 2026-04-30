#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL2/SDL.h>
#include <cstdint>

class InputManager
{
public:
    void update();
    bool isKeyPressed(SDL_Scancode key) const;

private:
    const Uint8* m_keyboardState = nullptr;
};

#endif