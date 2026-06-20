#include <Systems/InputManager.h>
#include <cassert>

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
                assert(false && "Unhandled key");
                return SDL_SCANCODE_UNKNOWN;
        }
    }
}

void InputManager::update()
{
    int numKeys = 0;

    const Uint8* keyboardState = SDL_GetKeyboardState(&numKeys);
    m_keyboardPreviousState = std::move(m_keyboardCurrentState);
    m_keyboardCurrentState.assign(keyboardState, keyboardState + numKeys);
}

bool InputManager::isKeyHeld(Key key) const
{
    const SDL_Scancode scancode = toSDLScancode(key);
    return !m_keyboardCurrentState.empty() && m_keyboardCurrentState[scancode];
}

bool InputManager::isKeyJustPressed(Key key) const
{
    const SDL_Scancode scancode = toSDLScancode(key);
    if (m_keyboardCurrentState.empty() || m_keyboardPreviousState.empty())
        return false;
    return m_keyboardCurrentState[scancode] && !m_keyboardPreviousState[scancode];
}