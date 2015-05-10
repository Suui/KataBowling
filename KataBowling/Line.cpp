#include "Line.h"
#include "FrameInterpreter.h"
#include "ScoreCalculator.h"


Line::Line(const std::string& Input): RawInput(Input)
{
	SetFrames(Input);
}


void Line::SetFrames(const std::string Input)
{
	int j = 0;
	for (auto i = 0; i < 9; i++)
	{
		if (Input.at(j) == 'X')
		{
			Frames[i] = FrameInterpreter::interpret(Input.at(j));
			j++;
		}
		else
		{
			Frames[i] = FrameInterpreter::interpret(Input.at(j), Input.at(j + 1));
			j += 2;
		}
	}

	SetLastFrame(Input, j);
}


void Line::SetLastFrame(const std::string Input, int j)
{
	if (j - Input.length() == 3) 
		Frames[10] = FrameInterpreter::interpret(Input.at(j + 1), Input.at(j + 2), Input.at(j + 3));
}


int Line::GetScore()
{
	return 0;
}