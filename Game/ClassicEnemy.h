#ifndef CLASSIC_ENEMY_H
#define CLASSIC_ENEMY_H

#include <Enemy.h>

class ClassicEnemy : public Enemy
{
public:
    explicit ClassicEnemy(Position position, const GameContext& context);
};

#endif