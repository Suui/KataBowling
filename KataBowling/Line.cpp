#include "Line.h"


Line::Line(std::string input)
{
	int j = 0;
	for (int i = 0; i < input.length(); i += 2)
	{
		frames[j] = Frame({ input.at(i), input.at(i+1) });
		j++;
	}

}


int Line::score()
{
	int sum = 0;
	for (int i = 0; i < FRAMES_IN_LINE; ++i)
	{
		sum += frames[i].knocks();
		if (frames[i].isSpare()) sum += frames[i + 1].knocks();
	}

	return sum;
}