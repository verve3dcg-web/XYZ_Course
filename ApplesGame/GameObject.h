#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"
#include "consts.h"
#include "player.h"
#include "Graphic.h"

namespace ApplesGame
{
    struct Game;

    struct GameObject
    {
        ObjectType type;
        Position2D position;
        sf::CircleShape shape;
        int scores = 0;
        sf::Sprite sprite;
        bool status = false;
    };

    //int* gameObjectsArray = new int[TOTAL_OBJECTS];

    void InitGameObjects(Game& Stat, const PlayerStat& playerStat, GraphicResource& graphicResource);
    void DrowGameObjects(GameObject& objectStat, sf::RenderWindow& window);
    int CalculationGameObjects(Game& Stat);
}