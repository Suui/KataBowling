#include "ScoreCalculator.h"


int ScoreCalculator::GetScore(Frame frames[])
{
	int score = 0;
	for (int i = 0; i < 9; i++)
	{
		score += frames[i].GetScore();
		if (frames[i].IsSpare()) score += frames[i + 1].GetFirstRoll();
	}
	score += frames[9].GetScore();
	
	return score;
}