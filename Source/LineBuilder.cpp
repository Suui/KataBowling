#include "LineBuilder.h"
#include "FrameParser.h"


void LineBuilder::FillFrames(std::string input, std::vector<Frame>& frames)
{
	unsigned int i = 0, j = 0;

	while (j < 9)
	{
		frames.push_back(FrameParser().Parse(input.substr(i, 3)));
		if (frames[j].IsStrike()) --i;
		i += 2;
		j++;
	}

	frames.push_back(FrameParser().Parse(input.substr(i, input.length() - i)));
}