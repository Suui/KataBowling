#pragma once
#include <vector>

class Frame
{
	std::vector<char> rolls;

public:

	Frame();

	explicit Frame(const std::vector<char>& rolls);

	int knocks();

	int parseToInt(char roll);
	
	bool isSpare();

	bool isStrike();
};
