#pragma once
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "math.h"
#include "Graphic.h"
namespace ApplesGame
{
    // Player statistic
    struct PlayerStatistic
    {
        int scores = 0;
        int numEatenApple = 0;
        float gameTime = 0;
    };
    struct PlayerStat
    {
        // Player data
        PlayerStatistic playerStatistic;
        Position2D playerPosition2D = { PLAYER_POSITION_X, PLAYER_POSITION_Y };
        float playerSpeed = INITIAL_SPEED;
        Direction playerDirection = Direction::Right;
        sf::Sprite Sprite;
    };

    void InitPlayer(PlayerStat& playerStat, GraphicResource& graphicResource);
    void DrowPlayer(PlayerStat& playerStat, sf::RenderWindow& windo);
}