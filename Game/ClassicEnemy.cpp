#include <ClassicEnemy.h>

ClassicEnemy::ClassicEnemy(Position position, const GameContext& context)
                : Enemy("ClassicEnemy", position, Velocity{20.0f, 20.0f},
                        Appearance{ShapeType::Rectangle, Size{28, 28}, Color{220, 60, 60}}, context)
{}