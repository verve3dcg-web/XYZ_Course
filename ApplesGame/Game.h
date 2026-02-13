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
    typedef unsigned char GameModeMask;

    enum GameMode : GameModeMask {
        IsModeNone = 0,// Without modifications
        IsGameInfinite = 1 << 0, // Endless spawn of apples
        IsIncreaseSpeed = 1 << 1, // Increased speed when eating apples
        IsIgnoringStones = 1 << 2, // Ignoring the stones
    };

    struct Game
    {
        //
        GameModeMask currentMode = IsModeNone;
        //GameObject objects[TOTAL_OBJECTS];
        std::vector<GameObject> objects;

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
