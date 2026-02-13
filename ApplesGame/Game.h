#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"
#include "consts.h"
#include "GameObject.h"
#include "player.h"
#include "Graphic.h"
#include "Sound.h"
namespace ApplesGame
{
    struct Game
    {
        GameObject objects[TOTAL_OBJECTS];
        bool isGameFinished = false;
        bool IsPaused = false;
        bool isRestarted = false;
        float gameFinishTime = 0.f;
        float restartTime = 0.f;
    };

 
    Position2D GetRandomFreePosition(const Game& Stat, const Position2D& Position2, float objectSize);
    void InitGame(Game& Stat, PlayerStat& playerStat, GraphicResource& graphicResource, AudioResource& audioResource);
    void RestartGame(Game& Stat, PlayerStat& playerStat, GraphicResource& graphicResource);
    void GameUpdate(Game& Stat, float deltaTime, float currentTime, PlayerStat& playerStat, AudioResource& audio);
    void GameDraw(Game& GameStat, sf::RenderWindow& window, const sf::RectangleShape& background, PlayerStat& playerStat);
    
}
