#pragma once

#include <SFML/Graphics.hpp>
#include "consts.h"
namespace ApplesGame
{
    struct Record
    {
        std::string name;
        int score;
    };


    void InitLeaderboardData();

    void UpdateLeaderboard(int newScore);

    std::string GetLeaderboardString();
}