#include "Frame.h"

Frame::Frame(int FirstRoll, int SecondRoll)
{
	rolls[0] = FirstRoll;
	rolls[1] = SecondRoll;
}

int Frame::GetScore()
{
	return rolls[0] + rolls[1];
}