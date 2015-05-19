#pragma once
#include <vector>

class Frame
{
	std::vector<int> rolls;

public:

	Frame();

	explicit Frame(std::vector<char> rolls);

	int knocks();

	int firstRoll();

	int secondRoll();

	int parseToInt(char roll);
	
	bool isSpare();

	bool isStrike();
};
