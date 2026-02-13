#pragma once
namespace ApplesGame
{
	enum class Direction { Right = 0, Up, Left, Down };
	enum class ObjectType { Apple, Stone };

	const std::string RESOURCES_PATH = "Resources/";

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Player constants
	const float INITIAL_SPEED = 100.f;
	const float PLAYER_SIZE = 20.f;
	const float PLAYER_ACCELERATION = 5.f;
	const float PLAYER_POSITION_X = SCREEN_WIDTH / 2.f;
	const float PLAYER_POSITION_Y = SCREEN_HEIGHT / 2.f;

	// Objects constants
	const int NUM_APPLES = 25;
	const float APPLE_SIZE = 20.f;
	const int NUM_APPLES_SPECIAL = 5;
	const int SCORES_SIMPLE_APPLE = 2;
	const int SCORES_SPECIAL_APPLE = 7;

	const int NUM_STONE = 8;
	const int STONE_SIZE = 30;
	const int TOTAL_OBJECTS = NUM_APPLES + NUM_STONE;

	// Sound
	const std::string SOUND_EAT_PATH = RESOURCES_PATH + "AppleEat.wav";
	const std::string SOUND_DEATH_PATH = RESOURCES_PATH + "Death.wav";
	const std::string MUSIC_THEME_PATH = RESOURCES_PATH + "Music.ogg";

	// Game State constants
	const float PAUSE_LENGTH = 2.f;
}

