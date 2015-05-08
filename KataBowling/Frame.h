#pragma once
#include <vector>

class Frame
{
	std::vector<int> rolls;

public:

	Frame(int FirstRoll, int SecondRoll);

	Frame(int FirstRoll, int SecondRoll, int LastRoll);

	int GetScore();

	bool IsSpare();

	bool IsStrike();

	bool IsLastFrame();
};
