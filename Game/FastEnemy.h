#ifndef FAST_ENEMY_H
#define FAST_ENEMY_H

#include <Enemy.h>

class FastEnemy : public Enemy
{
public:
    FastEnemy(Position position, const GameContext& context);
};

#endif