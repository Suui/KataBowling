#pragma once
#include <vector>

class Frame
{
	std::vector<char> rolls;

public:

	explicit Frame(const std::vector<char>& rolls);

	int knocks();

	int parseToInt(char roll);
	
	bool isStrike();
};
