#ifndef GAME_CONTROLS_H
#define GAME_CONTROLS_H

#include <Core/Globals.h>

enum class GameAction
{
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    Shoot,
    Restart
};

Key toKey(GameAction action);

#endif