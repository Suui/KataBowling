#include "FrameParser.h"
#include "FrameBuilder.h"


Frame FrameParser::Parse(std::string input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
		rolls.push_back(ParseToInt(i, input[i]));

	return FrameBuilder().Build(rolls);
}


int FrameParser::ParseToInt(int index, char roll)
{
	if (roll == 'X') return 10;
	if (roll == '/') return 10 - rolls[index - 1];
	if (roll == '-') return 0;
	return roll - '0';
}
