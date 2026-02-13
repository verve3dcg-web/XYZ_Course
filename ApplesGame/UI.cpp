#include "UI.h"
#include "Game.h"
#include "Player.h"
#include <string>

namespace ApplesGame
{
	void InitUI(UIState& uiState, const sf::Font& font)
	{

		uiState.scoreText.setFont(font);
		uiState.scoreText.setCharacterSize(12);
		uiState.scoreText.setFillColor(sf::Color::Yellow);
		uiState.scoreText.setString("Scores: 0");


		uiState.inputHintText.setFont(font);
		uiState.inputHintText.setCharacterSize(12);
		uiState.inputHintText.setFillColor(sf::Color::White);
		uiState.inputHintText.setString("Use arrows to move, ESC to exit");

		sf::FloatRect hintBounds = uiState.inputHintText.getLocalBounds();
		uiState.inputHintText.setOrigin(hintBounds.left + hintBounds.width, hintBounds.top);

		uiState.inputControlText.setFont(font);
		uiState.inputControlText.setCharacterSize(12);
		uiState.inputControlText.setFillColor(sf::Color::White);
		uiState.inputControlText.setString("R - Restart, WASD - Direction, Space - Pause, Q/1,2,3,4 - GameMod");

		uiState.inputControlText.setOrigin(hintBounds.left + hintBounds.width, hintBounds.top);


		uiState.gameStatusText.setFont(font);
		uiState.gameStatusText.setCharacterSize(72);
		uiState.gameStatusText.setStyle(sf::Text::Bold);
		uiState.gameStatusText.setFillColor(sf::Color::Yellow);
		uiState.gameStatusText.setString("GAME STATUS");


		sf::FloatRect goBounds = uiState.gameStatusText.getLocalBounds();
		uiState.gameStatusText.setOrigin(goBounds.left + goBounds.width / 2.0f,
			goBounds.top + goBounds.height / 2.0f);
	}

	void UpdateUI(UIState& uiState, const Game& game, const PlayerStat& playerStat)
	{
		//uiState.scoreText.setString("Scores: " + std::to_string(playerStat.playerStatistic.scores));
		std::string scoreStr = "Scores: " + std::to_string(playerStat.playerStatistic.scores);

		std::string modesStr = " | Modes: ";
		if (game.currentMode == IsModeNone) modesStr += "{Normal}";
		if (game.currentMode & IsGameInfinite) modesStr += "[IsGameInfinite] ";
		if (game.currentMode & IsIncreaseSpeed) modesStr += "[IsIncreaseSpeed] ";
		if (game.currentMode & IsIgnoringStones) modesStr += "[IsIgnoringStones] ";
		uiState.scoreText.setString(scoreStr + modesStr);
	}

	void ApplesGame::DrawUI(UIState& uiState, sf::RenderWindow& window, Game& gameStat)
	{
		uiState.scoreText.setPosition(10.f, 10.f);
		window.draw(uiState.scoreText);

		uiState.inputHintText.setPosition(window.getSize().x - 210.f, 10.f);
		window.draw(uiState.inputHintText);

		uiState.inputControlText.setPosition(window.getSize().x - 210.f, 25.f);
		window.draw(uiState.inputControlText);

		uiState.gameStatusText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

		if (gameStat.isGameFinished)
		{
			uiState.gameStatusText.setFillColor(sf::Color::Yellow);
			uiState.gameStatusText.setString("GAME OVER");
			window.draw(uiState.gameStatusText);
		}
		if (gameStat.IsPaused)
		{
			uiState.gameStatusText.setFillColor(sf::Color::White);
			uiState.gameStatusText.setString("/<<PAUSE>>/");
			window.draw(uiState.gameStatusText);
		}
	}
}