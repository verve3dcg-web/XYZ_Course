#pragma once
#include "Game.h"
#include "Sound.h"
namespace ApplesGame
{
    Position2D GetRandomFreePosition(const Game& Stat, const Position2D& Position2, float objectSize)
    {
        Position2D newPos;
        bool isOverlapping = true;

        while (isOverlapping)
        {
            isOverlapping = false;

            newPos.x = (rand() / (float)RAND_MAX) * (SCREEN_WIDTH - objectSize) + objectSize / 2.f;
            newPos.y = (rand() / (float)RAND_MAX) * (SCREEN_HEIGHT - objectSize) + objectSize / 2.f;

            if (IsOverlapping(newPos, objectSize / 2.f, Position2, PLAYER_SIZE*2))
            {
                isOverlapping = true;
                continue;
            }

            for (int i = 0; i < TOTAL_OBJECTS; ++i)
            {

                if (Stat.objects[i].position.x == 0 && Stat.objects[i].position.y == 0) continue;

                float otherSize = (Stat.objects[i].type == ObjectType::Stone) ? STONE_SIZE : APPLE_SIZE;

                if (IsOverlapping(newPos, objectSize / 2.f, Stat.objects[i].position, otherSize / 2.f))
                {
                    isOverlapping = true;
                    break;
                }
            }
        }
        return newPos;
    }

    void InitGame(Game& Stat, PlayerStat& playerStat, GraphicResource& graphicResource, AudioResource& audioResource)
    {
        InitGraphicResource(graphicResource);
        InitAudio(audioResource);
        RestartGame(Stat, playerStat, graphicResource);

    }
    void RestartGame(Game& Stat, PlayerStat& playerStat, GraphicResource& graphicResource)
    {
        Stat = Game();
        playerStat = PlayerStat();
        InitPlayer(playerStat, graphicResource);
        InitGameObjects(Stat, playerStat, graphicResource);
    }
    void GameUpdate(Game& Stat, float deltaTime, float currentTime, PlayerStat& playerStat, AudioResource& audio)
    {
        // Input handling inside update
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) playerStat.playerDirection = Direction::Right;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) playerStat.playerDirection = Direction::Up;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) playerStat.playerDirection = Direction::Left;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) playerStat.playerDirection = Direction::Down;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playerStat.playerDirection = Direction::Right;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) playerStat.playerDirection = Direction::Up;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) playerStat.playerDirection = Direction::Left;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playerStat.playerDirection = Direction::Down;

        // Movement
        switch (playerStat.playerDirection)
        {
        case Direction::Right: playerStat.playerPosition2D.x += playerStat.playerSpeed * deltaTime; break;
        case Direction::Up:    playerStat.playerPosition2D.y -= playerStat.playerSpeed * deltaTime; break;
        case Direction::Left:  playerStat.playerPosition2D.x -= playerStat.playerSpeed * deltaTime; break;
        case Direction::Down:  playerStat.playerPosition2D.y += playerStat.playerSpeed * deltaTime; break;
        }

        // Check screen borders
        if (playerStat.playerPosition2D.x - PLAYER_SIZE / 2.f < 0.f ||
            playerStat.playerPosition2D.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
            playerStat.playerPosition2D.y - PLAYER_SIZE / 2.f < 0.f ||
            playerStat.playerPosition2D.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
        {
            Stat.isGameFinished = true;
            Stat.gameFinishTime = currentTime;
            PlayDeathSound(audio);
        }

        // Check collisions
        for (int i = 0; i < TOTAL_OBJECTS; ++i)
        {
            float objSize = (Stat.objects[i].type == ObjectType::Stone) ? STONE_SIZE : APPLE_SIZE;

            if (IsOverlapping(playerStat.playerPosition2D, PLAYER_SIZE / 2.f, Stat.objects[i].position, objSize / 2.f))
            {
                if (Stat.objects[i].type == ObjectType::Stone)
                {
                    Stat.isGameFinished = true;
                    Stat.gameFinishTime = currentTime;
                    PlayDeathSound(audio);
                    break;
                }
                else if (Stat.objects[i].type == ObjectType::Apple)
                {
                    PlayEatSound(audio);
                    playerStat.playerStatistic.scores += Stat.objects[i].scores;
                    playerStat.playerStatistic.numEatenApple++;
                    playerStat.playerSpeed += PLAYER_ACCELERATION;
                    
                    

                    // Respawn apple
                    Stat.objects[i].position = { 0.f, 0.f };
                    Stat.objects[i].position = GetRandomFreePosition(Stat, playerStat.playerPosition2D, APPLE_SIZE);
                    Stat.objects[i].shape.setPosition(Stat.objects[i].position.x, Stat.objects[i].position.y);
                }
            }
        }
    }

    void GameDraw(Game& Stat, sf::RenderWindow& window, const sf::RectangleShape& background, PlayerStat& playerStat)
    {
        window.clear();
        window.draw(background);
        DrowPlayer(playerStat, window);
        for (int i = 0; i < TOTAL_OBJECTS; ++i) {
            Stat.objects[i].sprite.setPosition(Stat.objects[i].position.x, Stat.objects[i].position.y);
            window.draw(Stat.objects[i].sprite);
        }

        
       // window.display();
    }
}
