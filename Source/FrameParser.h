#pragma once
#include "Frame.h"


class FrameParser
{
	std::vector<int> rolls;

	Frame BuildFrame();

	int CalculateBonus(int bonusRolls);

	int ParseToInt(int rollNumber, char roll);

	bool IsStrike();

	bool IsSpare();


public:

	Frame Parse(std::string input);


};
