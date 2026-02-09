#include "Graphic.h"
#include <cassert>
#include "Consts.h"

namespace ApplesGame
{
	void InitGraphicResource(GraphicResource& graphicResource)
	{
		assert(graphicResource.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(graphicResource.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(graphicResource.appleSpecialTexture.loadFromFile(RESOURCES_PATH + "\\AppleSpecial.png"));
		assert(graphicResource.stoneTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
	}
	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect  spriteRect  = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}
	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}