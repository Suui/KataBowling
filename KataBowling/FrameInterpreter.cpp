#include "FrameInterpreter.h"


Frame FrameInterpreter::interpret(char FirstRoll)
{
	if (FirstRoll == 'X') return Frame(10, 0);
	return Frame();
}


Frame FrameInterpreter::interpret(char FirstRoll, char SecondRoll)
{
	if (FirstRoll == 'G') return GetFirstRollIsZeroInterpretation(SecondRoll);

	int First = FirstRoll - '0'; 
	return GetFirstRollNotZeroInterpretation(SecondRoll, First);
}


Frame FrameInterpreter::GetFirstRollNotZeroInterpretation(char SecondRoll, int First)
{
	if (SecondRoll == '-') return Frame(First, 0);
	if (SecondRoll == '/') return Frame(First, 10 - First);
	return Frame(First, SecondRoll - '0');
}


Frame FrameInterpreter::GetFirstRollIsZeroInterpretation(char SecondRoll)
{
	if (SecondRoll == '-') return Frame(0, 0);
	if (SecondRoll == '/') return Frame(0, 10);
	return Frame(0, SecondRoll - '0');
}


Frame FrameInterpreter::interpret(char FirstRoll, char SecondRoll, char LastRoll)
{
	Frame frame = interpret(FirstRoll, SecondRoll);
	if (LastRoll == 'X') return Frame(frame.GetFirstRoll(), frame.GetSecondRoll(), 10);
	return Frame(frame.GetFirstRoll(), frame.GetSecondRoll(), LastRoll - '0');
}
