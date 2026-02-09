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
    };
/*
    void ClearGameObjects(Game& game);
    void InitGameObjectData(GameObject& object, int index, GraphicResource& graphicResource);
    void InitGameObjectTransform(GameObject& object, float size);
    void SpawnGameObject(Game& game, GameObject& object, const PlayerStat& playerStat, float size);
*/
    void InitGameObjects(Game& Stat, const PlayerStat& playerStat, GraphicResource& graphicResource);
    void DrowGameObjects(GameObject& objectStat, sf::RenderWindow& window);
}