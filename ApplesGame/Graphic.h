#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
    struct GraphicResource
    {
        sf::Texture playerTexture;
        sf::Texture appleTexture;
        sf::Texture appleSpecialTexture;
        sf::Texture stoneTexture;
    };
    void InitGraphicResource(GraphicResource& graphicResource);
    void InitSprite(sf::Sprite& sprite, sf::Texture& Texture, float gameObjectSize);
    void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);
    void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);
}