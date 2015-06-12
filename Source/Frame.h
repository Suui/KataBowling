#pragma once
#include <vector>

class Frame
{
	std::vector<int> rolls;
	int bonus;


public:

	Frame();

	explicit Frame(std::vector<int> rolls, int bonus);

	int FirstRoll();
	
	int SecondRoll();
	
	int Knocks();
	
	int Bonus();

	bool IsSpare();

	bool IsStrike();
};
