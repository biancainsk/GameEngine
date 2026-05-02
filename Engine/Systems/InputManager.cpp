#include <Systems/InputManager.h>

void InputManager::update()
{
    SDL_PumpEvents();
    m_keyboardState = SDL_GetKeyboardState(nullptr);
}

bool InputManager::isKeyPressed(SDL_Scancode key) const
{
    return m_keyboardState && m_keyboardState[key];
}