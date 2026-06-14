#include <FastEnemy.h>

FastEnemy::FastEnemy(Position position, const GameContext& context)
                : Enemy("FastEnemy", position, Velocity{80.0f, 80.0f},
                        Appearance{ShapeType::Rectangle, Size{18, 18}, Color{255, 140, 0}}, context)
{}