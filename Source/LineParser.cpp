#include "LineParser.h"


void LineParser::FillFrames(std::string input, Frame* frames)
{
	int j = 0;
	for (unsigned int i = 0; i < input.length(); i += 2)
	{
		if (input.at(i) == 'X')
		{
			frames[j] = Frame({ 'X' });
			j++;
			--i;
			continue;
		}
		frames[j] = Frame({ input.at(i), input.at(i + 1) });
		j++;
	}
}