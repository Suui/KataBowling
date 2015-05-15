#include "Frame.h"


Frame::Frame(const std::vector<char>& input)
{
	for (char c : input)
		rolls.push_back(parseToInt(c));
}


int Frame::knocks()
{
	int sum = 0;
	for (int roll : rolls)
		sum += roll;
	return sum;
}


int Frame::parseToInt(char roll)
{
	if (roll == 'X') return 10;
	if (roll == '/') return 10 - rolls[0];
	if (roll == '-') return 0;
	return roll - '0';
}