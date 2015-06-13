#pragma once
#include <vector>

class Frame;


class FrameBuilder
{
	std::vector<int> rolls;

	int CalculateBonus();

	bool IsStrike();

	bool IsSpare();


public:

	Frame Build(std::vector<int> rolls);
};
