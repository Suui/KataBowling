#pragma once

#include "../Frame/Frame.h"


class Line
{
	const int FRAMES_IN_LINE = 10;
	std::vector<Frame> frames;


public:

	explicit Line(std::vector<Frame> frames);

	int Score();
};
