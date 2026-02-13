#pragma once
#include "GameObject.h"
#include "Game.h"

#include <cstdlib>

namespace ApplesGame
{
	int numApples;
	int numStones;

	void InitSprite(sf::Sprite& sprite, sf::Texture& Texture, float gameObjectSize)
	{
		sprite.setTexture(Texture);
		SetSpriteSize(sprite, gameObjectSize, gameObjectSize);
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}
	void InitGameObjects(Game& Stat, const PlayerStat& playerStat, GraphicResource& graphicResource)
	{
		//int totalObjectsCount = CalculationArrayObjects(Stat);
		//GameObject* arrayGameObjects = new GameObject[totalObjectsCount];
		int totalObjectsCount = CalculationGameObjects(Stat);
		
		for (int i = 0; i < totalObjectsCount; ++i)
		{
			float size;
			if (i < numStones) //
			{
				Stat.objects[i].type = ObjectType::Stone;
				Stat.objects[i].status = true;
				Stat.objects[i].scores = 0;
				size = STONE_SIZE;
				InitSprite(Stat.objects[i].sprite, graphicResource.stoneTexture, size);
			}
			else
			{
				Stat.objects[i].type = ObjectType::Apple;
				Stat.objects[i].status = true;
				size = APPLE_SIZE;
				//
				if (rand() % 100 < DROPOUT_APPLES_SPECIAL)
				{
					Stat.objects[i].scores = SCORES_SPECIAL_APPLE;
					InitSprite(Stat.objects[i].sprite, graphicResource.appleSpecialTexture, size);
				}
				else
				{
					Stat.objects[i].scores = SCORES_SIMPLE_APPLE;
					InitSprite(Stat.objects[i].sprite, graphicResource.appleTexture, size);
				}
			}

			
			Stat.objects[i].position = GetRandomFreePosition(Stat, playerStat.playerPosition2D, size);
			Stat.objects[i].sprite.setPosition(Stat.objects[i].position.x, Stat.objects[i].position.y);
		}
		return;
	}

	void DrowGameObjects(GameObject& objectStat, sf::RenderWindow& window)
	{
		objectStat.sprite.setPosition(objectStat.position.x, objectStat.position.y);
		window.draw(objectStat.sprite);
	}

	int CalculationGameObjects(Game& Stat)
	{
		int totalObjectsCount = MIN_OBJECTS + rand() % MAX_OBJECTS;
		numApples = static_cast<int>(totalObjectsCount * PERCENT_APPLES);
		numStones = totalObjectsCount - numApples;

		Stat.objects.clear();
		Stat.objects.resize(totalObjectsCount);

		return totalObjectsCount;

	}
	/*
	int CalculationArrayObjects(Game& Stat)
	{
		int totalObjectsCount = MIN_OBJECTS + rand() % MAX_OBJECTS;
		numApples = static_cast<int>(totalObjectsCount * PERCENT_APPLES);
		numStones = totalObjectsCount - numApples;
		return totalObjectsCount;

	}*/
}
