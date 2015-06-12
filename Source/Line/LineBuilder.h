#pragma once

#include <vector>

class Frame;
class Line;



class LineBuilder
{
	static void FillFrames(std::string& input, std::vector<Frame>& frames);


public:

	static Line Build(std::string input);
};
