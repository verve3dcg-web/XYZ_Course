#pragma once
namespace ApplesGame
{
    struct Vector2D
    {
        float x = 0;
        float y = 0;
    };
    typedef Vector2D Position2D;
    bool IsOverlapping(Position2D Position1, float radius1, Position2D Position2, float radius2);

}