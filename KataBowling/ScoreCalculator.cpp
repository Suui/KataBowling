#include "ScoreCalculator.h"


int ScoreCalculator::GetScore(Frame frames[])
{
	int score = 0;
	for (int i = 0; i < 10; ++i)
		score += frames[i].GetScore();
	
	return score;
}