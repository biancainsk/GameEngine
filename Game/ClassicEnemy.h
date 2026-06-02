#ifndef CLASSIC_ENEMY_H
#define CLASSIC_ENEMY_H

#include <Enemy.h>

class ClassicEnemy : public Enemy
{
public:
    explicit ClassicEnemy(Position position);

    // void update(float dt);
    // void render(const Renderer& renderer) const override;
};

#endif