#include <Systems/InputManager.h>
#include <Core/Globals.h>

namespace
{
    SDL_Scancode toSDLScancode(Key key)
    {
        switch (key)
        {
            case Key::W:
                return SDL_SCANCODE_W;

            case Key::A:
                return SDL_SCANCODE_A;

            case Key::S:
                return SDL_SCANCODE_S;

            case Key::D:
                return SDL_SCANCODE_D;

            case Key::Space:
                return SDL_SCANCODE_SPACE;

            case Key::R:
                return SDL_SCANCODE_R;

            default:
                return SDL_SCANCODE_UNKNOWN;
        }
    }
}

void InputManager::update()
{
    m_keyboardState = SDL_GetKeyboardState(nullptr);
}

bool InputManager::isKeyPressed(Key key) const
{
    const SDL_Scancode scancode = toSDLScancode(key);

    return m_keyboardState && m_keyboardState[scancode];
}