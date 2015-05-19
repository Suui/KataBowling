#include "Frame.h"


Frame::Frame() {}


Frame::Frame(std::vector<char> input)
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


int Frame::firstRoll()
{
	return rolls[0];
}


int Frame::secondRoll()
{
	if (rolls.size() > 1) return rolls[1];
}


int Frame::parseToInt(char roll)
{
	if (roll == 'X') return 10;
	if (roll == '/') return 10 - rolls[0];
	if (roll == '-') return 0;
	return roll - '0';
}


bool Frame::isSpare()
{
	return rolls[0] < 10 && knocks() == 10;
}


bool Frame::isStrike()
{
	return rolls[0] == 10;
}