#pragma once
#include "Frame.h"


class FrameParser
{
	std::vector<int> rolls;

	int ParseToInt(int rollNumber, char roll);


public:

	Frame Parse(std::string input);


};
