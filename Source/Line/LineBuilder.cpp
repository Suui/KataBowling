#include "LineBuilder.h"
#include "Line.h"
#include "../Frame/FrameParser.h"
#include "../Frame/Frame.h"


Line LineBuilder::Build(std::string input)
{
	std::vector<Frame> frames;
	FillFrames(input, frames);

	return Line(frames);
}


void LineBuilder::FillFrames(std::string& input, std::vector<Frame>& frames)
{
	unsigned i = 0, j = 0;

	while (j < 9)
	{
		frames.push_back(FrameParser().Parse(input.substr(i, 3)));
		if (frames[j].IsStrike()) --i;
		i += 2;
		j++;
	}

	frames.push_back(FrameParser().Parse(input.substr(i, input.length() - i)));
}
