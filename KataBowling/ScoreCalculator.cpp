#include "ScoreCalculator.h"


int ScoreCalculator::GetScore(Frame frames[])
{
	int score = 0;
	for (int i = 0; i < 9; i++)
	{
		score += frames[i].GetScore();
		if (frames[i].IsSpare()) score += frames[i + 1].GetFirstRoll();
		if (frames[i].IsStrike())
		{
			if (frames[i + 1].IsLastFrame() && frames[i + 1].GetFirstRoll() == 10)
			{
				score += 20;
				break;
			}
			score += 10 + frames[i + 1].GetScore();
		}
	}
	score += frames[9].GetScore();
	
	return score;
}