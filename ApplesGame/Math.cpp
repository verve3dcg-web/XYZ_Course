#pragma once
#include "math.h"
namespace ApplesGame
{
    bool IsOverlapping(Position2D Position1, float radius1, Position2D Position2, float radius2)
    {
        float dx = Position1.x - Position2.x;
        float dy = Position1.y - Position2.y;
        float distanceSq = dx * dx + dy * dy;
        float radiusSum = radius1 + radius2;
        return distanceSq < (radiusSum * radiusSum);
    }
}