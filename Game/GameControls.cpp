#include <GameControls.h>

Key toKey(GameAction action)
{
    switch (action)
    {
        case GameAction::MoveUp:
            return Key::W;

        case GameAction::MoveDown:
            return Key::S;

        case GameAction::MoveLeft:
            return Key::A;

        case GameAction::MoveRight:
            return Key::D;

        case GameAction::Shoot:
            return Key::Space;

        case GameAction::Restart:
            return Key::R;
    }

    return Key::Space;
}