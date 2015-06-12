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
		sum += frames[i].Knocks() + frames[i].Bonus();

	return sum;
}