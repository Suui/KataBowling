#pragma once
#include <vector>


class Frame
{
	std::vector<int> rolls;


public:

	Frame();

	Frame(int FirstRoll, int SecondRoll);

	Frame(int FirstRoll, int SecondRoll, int LastRoll);

	int GetScore();

	bool IsSpare();

	bool IsStrike();

	bool IsLastFrame();

	int GetFirstRollScore() const { return rolls[0]; }

	int GetSecondRollScore() const { return rolls[1]; }

	int GetThirdRollScore() { if (IsLastFrame()) return rolls[3]; }

	std::vector<int> GetRolls() const { return rolls; }
};
