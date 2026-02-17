#include "Leaderboard.h"

namespace ApplesGame
{
    int applesLeaderBoard;

    std::vector<Record> leaderboard = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0}
    };
    void InitLeaderboardData()
    {
        applesLeaderBoard = LEADERBOARD_MIN + rand() % LEADERBOARD_MAX;

        leaderboard[0].score = applesLeaderBoard;
        leaderboard[1].score = applesLeaderBoard / 2;
        leaderboard[2].score = applesLeaderBoard / 3;
        leaderboard[3].score = applesLeaderBoard / 4;
        leaderboard.push_back({ "Player", 0 });
    }
    void UpdateLeaderboard(int newScore)
    {
        int n = leaderboard.size() - 1;
        if (leaderboard[n].score < newScore)
        {
            leaderboard[n].score = newScore;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (leaderboard[j].score < leaderboard[j + 1].score) {
                        Record temp = leaderboard[j];
                        leaderboard[j] = leaderboard[j + 1];
                        leaderboard[j + 1] = temp;
                    }
                }
            }
        }

        /*
        if (leaderboard.size() > 5)
        {
            leaderboard.resize(5);
        }
        */
    }
    std::string GetLeaderboardString()
    {
        std::string str = "LEADERBOARD:\n";
        for (int i = 0; i < leaderboard.size(); ++i) {
            str += std::to_string(i + 1) + ". " + leaderboard[i].name + ": " + std::to_string(leaderboard[i].score) + "\n";
        }
        return str;
    }
}
