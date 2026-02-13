#pragma once
#include "GameObject.h"
#include "Game.h"

#include <cstdlib>

namespace ApplesGame
{
	void InitGameObjects(Game& Stat, const PlayerStat& playerStat, GraphicResource& graphicResource)
	{
		// clear position
		for (int i = 0; i < TOTAL_OBJECTS; ++i) Stat.objects[i].position = { 0, 0 };

		for (int i = 0; i < TOTAL_OBJECTS; ++i)
		{
			float size;
			if (i < NUM_STONE)
			{
				Stat.objects[i].type = ObjectType::Stone;
				Stat.objects[i].scores = 0;
				
				//Stat.objects[i].shape.setFillColor(sf::Color::White);
				size = STONE_SIZE;
				InitSprite(Stat.objects[i].sprite, graphicResource.stoneTexture, size);
			}
			else
			{
				Stat.objects[i].type = ObjectType::Apple;
				size = APPLE_SIZE;
				if (i >= TOTAL_OBJECTS - NUM_APPLES_SPECIAL)
				{
					Stat.objects[i].scores = SCORES_SPECIAL_APPLE;
					//Stat.objects[i].shape.setFillColor(sf::Color::Yellow);
					InitSprite(Stat.objects[i].sprite, graphicResource.appleSpecialTexture, size);
				}
				else
				{
					Stat.objects[i].scores = SCORES_SIMPLE_APPLE;
					//Stat.objects[i].shape.setFillColor(sf::Color::Green);
					InitSprite(Stat.objects[i].sprite, graphicResource.appleTexture, size);
				}
			}

			Stat.objects[i].shape.setRadius(size / 2.f);
			Stat.objects[i].shape.setOrigin(size / 2.f, size / 2.f);

			Stat.objects[i].position = GetRandomFreePosition(Stat, playerStat.playerPosition2D, size);
			Stat.objects[i].shape.setPosition(Stat.objects[i].position.x, Stat.objects[i].position.y);
		}
	}
	void InitSprite(sf::Sprite& sprite, sf::Texture& Texture, float gameObjectSize)
	{
		sprite.setTexture(Texture);
		SetSpriteSize(sprite, gameObjectSize, gameObjectSize);
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}
	void DrowGameObjects(GameObject& objectStat, sf::RenderWindow& window)
	{
		objectStat.sprite.setPosition(objectStat.position.x, objectStat.position.y);
		window.draw(objectStat.sprite);
	}
}
