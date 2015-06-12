#include "Frame.h"


Frame::Frame() {}


Frame::Frame(std::vector<int> rolls, int bonus) : rolls(rolls), bonus(bonus) {}


int Frame::Knocks() { return FirstRoll() + SecondRoll(); }


int Frame::Bonus() { return bonus; }


int Frame::FirstRoll() { return rolls[0]; }


int Frame::SecondRoll() { return rolls.size() > 1 ? rolls[1] : 0; }


bool Frame::IsSpare() { return rolls[0] < 10 && Knocks() == 10; }


bool Frame::IsStrike() { return rolls[0] == 10; }