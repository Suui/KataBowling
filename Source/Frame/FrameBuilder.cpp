#include "FrameBuilder.h"
#include "Frame.h"


Frame FrameBuilder::Build(std::vector<int> rolls)
{
	this->rolls = rolls;
	if (IsStrike()) return Frame({ 10 }, CalculateBonus(2));
	if (IsSpare()) return Frame({ rolls[0], rolls[1] }, CalculateBonus(1));
	return Frame({ rolls[0], rolls[1] }, 0);
}


int FrameBuilder::CalculateBonus(int bonusRolls)
{
	int sum = 0;
	for (unsigned int i = 3 - bonusRolls; i < rolls.size(); ++i)
		sum += rolls[i];
	return sum;
}


bool FrameBuilder::IsStrike() { return rolls[0] == 10; }


bool FrameBuilder::IsSpare() { return rolls[0] + rolls[1] == 10; }
