#include "LineParser.h"
#include "FrameParser.h"


void LineParser::FillFrames(std::string input, Frame* frames)
{
	unsigned int i = 0, j = 0;

	while (j < 9)
	{
		frames[j] = FrameParser().Parse(input.substr(i, 3));
		if (frames[j].IsStrike()) --i;
		i += 2;
		j++;
	}

	frames[j] = FrameParser().Parse(input.substr(i, input.length() - i));
}