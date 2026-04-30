#include "../Engine/Core/Engine.h"
#include "../Game/Game.h"

#include <iostream>

int main()
{
    Engine engine("Shooter Game", 800, 600);
    Game game;

    engine.run(game);

    return 0;
}