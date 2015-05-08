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


bool Frame::IsSpare()
{
	if (rolls[0] == 10) return false;
	return rolls[0] + rolls[1] == 10;
}


bool Frame::IsStrike()
{
	return rolls[0] == 10;
}