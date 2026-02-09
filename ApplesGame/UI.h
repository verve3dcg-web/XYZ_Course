#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{

	struct Game;
	struct PlayerStat;

	struct UIState
	{
		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text inputControlText;
		sf::Text gameStatusText;
	};


	void InitUI(UIState& uiState, const sf::Font& font);


	void UpdateUI(UIState& uiState, const Game& game, const PlayerStat& playerStat);

	void DrawUI(UIState& uiState, sf::RenderWindow& window, Game& gameStat);
}