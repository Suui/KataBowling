#include "FrameParser.h"


Frame FrameParser::Parse(std::string input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
		rolls.push_back(ParseToInt(i, input[i]));

	return BuildFrame();
}


Frame FrameParser::BuildFrame()
{
	if (IsStrike()) return Frame({ 10 }, CalculateBonus(2));
	if (IsSpare()) return Frame({ rolls[0], rolls[1] }, CalculateBonus(1));
	return Frame({ rolls[0], rolls[1] }, 0);
}


int FrameParser::CalculateBonus(int bonusRolls)
{
	int sum = 0;
	for (unsigned int i = 3 - bonusRolls; i < rolls.size(); ++i)
		sum += rolls[i];
	return sum;
}


int FrameParser::ParseToInt(int rollNumber, char roll)
{
	if (roll == 'X') return 10;
	if (roll == '/') return 10 - rolls[rollNumber - 1];
	if (roll == '-') return 0;
	return roll - '0';
}


bool FrameParser::IsStrike()
{
	return rolls[0] == 10;
}


bool FrameParser::IsSpare()
{
	return rolls[0] + rolls[1] == 10;
}
