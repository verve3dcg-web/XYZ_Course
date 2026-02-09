#pragma once
#include "player.h"
#include "Game.h"
#include "GameObject.h"
#include <cstdlib>


namespace ApplesGame
{
    void InitPlayer(PlayerStat& playerStat, GraphicResource& graphicResource)
    {

        // Init player sprite
        playerStat.Sprite.setTexture(graphicResource.playerTexture);
        SetSpriteSize(playerStat.Sprite, PLAYER_SIZE, PLAYER_SIZE);
        SetSpriteRelativeOrigin(playerStat.Sprite, 0.5f, 0.5f);
    }
    void DrowPlayer(PlayerStat& playerStat, sf::RenderWindow& window)
    {
        playerStat.Sprite.setPosition(playerStat.playerPosition2D.x, playerStat.playerPosition2D.y);

        float scaleX = PLAYER_SIZE / playerStat.Sprite.getLocalBounds().width;
        float scaleY = PLAYER_SIZE / playerStat.Sprite.getLocalBounds().height;

        switch (playerStat.playerDirection)
        {
        case Direction::Up:
            playerStat.Sprite.setScale(scaleX, scaleY);
            playerStat.Sprite.setRotation(-90.f);
                break;

        case Direction::Right:
            playerStat.Sprite.setScale(scaleX, scaleY);
            playerStat.Sprite.setRotation(0.f);
                break;

        case Direction::Down:
            playerStat.Sprite.setScale(scaleX, scaleY);
            playerStat.Sprite.setRotation(90.f);
                break;

        case Direction::Left:

            playerStat.Sprite.setScale(-scaleX, scaleY);
            playerStat.Sprite.setRotation(0.f);
                break;
        }

        window.draw(playerStat.Sprite);
    }
}