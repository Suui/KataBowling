#include "Line.h"


Line::Line(std::string input)
{
	for (int i = 0; i < FRAMES_IN_LINE; ++i)
		frames[i] = Frame({ '-', '-' });
}


int Line::score()
{
	return 0;
}