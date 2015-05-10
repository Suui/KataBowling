#pragma once
#include "Frame.h"


class FrameInterpreter
{
	static Frame GetFirstRollIsZeroInterpretation(char SecondRoll);

	static Frame GetFirstRollNotZeroInterpretation(char SecondRoll, int First);


public:

	static Frame interpret(char FirstRoll);

	static Frame interpret(char FirstRoll, char SecondRoll);

	static Frame interpret(char FirstRoll, char SecondRoll, char LastRoll);
};
