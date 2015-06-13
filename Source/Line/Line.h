#pragma once

#include "../Frame/Frame.h"


class Line
{
	std::vector<Frame> frames;


public:

	explicit Line(std::vector<Frame> frames);

	int Score();
};
