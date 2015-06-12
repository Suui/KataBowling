#pragma once
#include "Frame.h"


class Line
{
	const int FRAMES_IN_LINE = 10;
	std::vector<Frame> frames;


public:

	Line(std::string input);

	int Score();
};
