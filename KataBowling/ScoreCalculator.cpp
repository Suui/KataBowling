#include "ScoreCalculator.h"


int ScoreCalculator::GetScore(Frame frames[])
{
	int score = 0;
	for (int i = 0; i < 9; i++)
	{
		score += frames[i].GetScore();
		if (frames[i].IsLastFrame()) break;
		if (frames[i].IsSpare()) score += frames[i + 1].GetFirstRollScore();
		if (frames[i].IsStrike()) score += frames[i + 1].GetScore();
		if (frames[i + 1].IsStrike()) 
		{
			if (frames[i + 1].IsLastFrame())
				score += frames[i + 1].GetFirstRollScore() + frames[i+1].GetSecondRollScore();
			else
				score += frames[i + 2].GetFirstRollScore();
		}
	}
	
	return score;
}


int ScoreCalculator::GetScore(Frame frame)
{
	int score = 0;
	for (int rollScore : frame.GetRolls())
		score += rollScore;
	return score;
}