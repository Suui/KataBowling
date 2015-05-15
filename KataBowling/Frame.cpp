#include "Frame.h"


Frame::Frame(const std::vector<char>& rolls): rolls(rolls) {}


int Frame::knocks()
{
	int sum = 0;
	for (auto&& roll : rolls)
		sum += parseToInt(roll);
	return sum;
}


int Frame::parseToInt(char roll)
{
	if (roll == '-') return 0;
	return roll - '0';
}