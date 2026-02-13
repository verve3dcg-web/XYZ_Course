
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "consts.h"
#include "Game.h"
#include "Sound.h"
#include "UI.h"

namespace ApplesGame
{
bool bIsPaused = false;

void EventInput(sf::RenderWindow& window, Game& gameStat, float currentTime, PlayerStat& playerStat, GraphicResource& graphicResource)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            else if (event.key.code == sf::Keyboard::Space)
            {
                gameStat.IsPaused = !gameStat.IsPaused;
                bIsPaused = !bIsPaused;
            }
            else if (event.key.code == sf::Keyboard::R)
            {
                RestartGame(gameStat, playerStat, graphicResource);
                gameStat.isRestarted = true;
                gameStat.restartTime = currentTime;
                bIsPaused = false;
                gameStat.IsPaused = false;
            }
            if (event.key.code == sf::Keyboard::Q)
            {
 
                gameStat.currentMode++;


                if (gameStat.currentMode > 15)
                {
                    gameStat.currentMode = IsModeNone;
                }
            }
            // Переключение режимов
            if (event.key.code == sf::Keyboard::Num1)
            {
                gameStat.currentMode ^= IsModeNone;
            }
            else if (event.key.code == sf::Keyboard::Num2)
            {
                gameStat.currentMode ^= IsGameInfinite;
            }
            else if (event.key.code == sf::Keyboard::Num3)
            {
                gameStat.currentMode ^= IsIncreaseSpeed;
            }
            else if (event.key.code == sf::Keyboard::Num4)
            {
                gameStat.currentMode ^= IsIgnoringStones;
            }
        }
    }
}
}


int main()
{
    using namespace ApplesGame;

    // Init Window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game");

    // Background setup
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    background.setFillColor(sf::Color::Black);
    background.setPosition(0.f, 0.f);

    // Random seed
    int seed = (int)time(nullptr);
    srand(seed);

    // Init Game State
    Game gameStat;
    PlayerStat playerStat;
    GraphicResource graphicResource;
    AudioResource audioResource;


    sf::Font font;

    if (!font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"))
    {

        return -1;
    }
    UIState uiState;
    InitUI(uiState, font);

    InitGame(gameStat, playerStat, graphicResource, audioResource);

    // Clock
    sf::Clock gameClock;
    float lastTime = gameClock.getElapsedTime().asSeconds();

    while (window.isOpen())
    {
        // Reduce framerate to not spam CPU and GPU
        sf::sleep(sf::milliseconds(16));
        float currentTime = gameClock.getElapsedTime().asSeconds();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        EventInput(window, gameStat, currentTime, playerStat, graphicResource);

        if (gameStat.isRestarted)
        {

            if (currentTime - gameStat.restartTime < 0.5f)
            {
                background.setFillColor(sf::Color::Blue);
            }
            else
            {
                gameStat.isRestarted = false;
                background.setFillColor(sf::Color::Black);
            }
        }
        else if (gameStat.isGameFinished)
        {
            background.setFillColor(sf::Color::Red);
            if (currentTime - gameStat.gameFinishTime > PAUSE_LENGTH)
            {
                RestartGame(gameStat, playerStat, graphicResource);
            }
        }
        else
        {
            background.setFillColor(sf::Color::Black);
            if (!gameStat.IsPaused)
            {
                GameUpdate(gameStat, deltaTime, currentTime, playerStat, audioResource);
                UpdateUI(uiState, gameStat, playerStat);
            }
        }


        GameDraw(gameStat, window, background, playerStat);
        DrawUI(uiState, window, gameStat);
        window.display();
    }

    return 0;
}