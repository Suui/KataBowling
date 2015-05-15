#pragma once
#include "Frame.h"

class Line
{
	const int FRAMES_IN_LINE = 10;
	Frame frames[10];

public:

	Line(std::string input);
	
	int score();
};
