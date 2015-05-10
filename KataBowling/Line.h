#pragma once
#include <string>
#include "Frame.h"


class Line
{
	std::string RawInput;
	Frame Frames[10];

	void SetFrames(const std::string Input);

	void SetLastFrame(const std::string Input, int j);


public:

	Line(const std::string& Input);

	int GetScore();

	inline Frame* GetFrames() { return Frames; }

	inline std::string GetRawInput() const { return RawInput; }
};
