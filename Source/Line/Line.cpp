#include "Line.h"
#include "../Frame/Frame.h"


Line::Line(std::vector<Frame> frames) : frames(frames) {}


int Line::Score()
{
	int sum = 0;
	for (int i = 0; i < frames.size(); ++i)
		sum += frames[i].Knocks() + frames[i].Bonus();

	return sum;
}
