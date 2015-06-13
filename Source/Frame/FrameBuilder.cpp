#include "FrameBuilder.h"
#include "Frame.h"


Frame FrameBuilder::Build(std::vector<int> rolls)
{
	this->rolls = rolls;
	if (IsStrike()) return Frame({ 10 }, CalculateBonus());

	return Frame({ rolls[0], rolls[1] }, CalculateBonus());
}


int FrameBuilder::CalculateBonus()
{
	int sum = 0, bonusRolls = GetBonusRolls();

	for (unsigned i = 3 - bonusRolls; i < rolls.size(); ++i)
		sum += rolls[i];
	return sum;
}


bool FrameBuilder::IsStrike() { return rolls[0] == 10; }


bool FrameBuilder::IsSpare() { return rolls[0] + rolls[1] == 10; }
