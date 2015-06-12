#include "Line.h"
#include "LineParser.h"


Line::Line(std::string input)
{
	LineParser::FillFrames(input, frames);
}


int Line::score()
{
	int sum = 0;
	for (int i = 0; i < FRAMES_IN_LINE; ++i)
	{
		sum += frames[i].knocks();
		if (frames[i].isSpare()) sum += frames[i + 1].firstRoll();
		if (frames[i].isStrike())
		{
			if (frames[i+1].isStrike())
				sum += 10 + frames[i + 2].firstRoll();
			else
				sum += frames[i + 1].firstRoll() + frames[i + 1].secondRoll();
		}
	}

	return sum;
}