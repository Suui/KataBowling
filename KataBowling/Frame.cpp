#include "Frame.h"
#include "ScoreCalculator.h"


Frame::Frame()
{
}


Frame::Frame(int FirstRoll, int SecondRoll)
{
	rolls.push_back(FirstRoll);
	rolls.push_back(SecondRoll);
}


Frame::Frame(int FirstRoll, int SecondRoll, int LastFrameExtraRoll)
{
	rolls.push_back(FirstRoll);
	rolls.push_back(SecondRoll);
	rolls.push_back(LastFrameExtraRoll);
}


int Frame::GetScore()
{
	return ScoreCalculator::GetScore(*this);
}


bool Frame::IsSpare()
{
	return rolls[0] < 10 && rolls[0] + rolls[1] == 10;
}


bool Frame::IsStrike()
{
	return rolls[0] == 10;
}


bool Frame::IsLastFrame()
{
	return rolls.size() == 3;
}