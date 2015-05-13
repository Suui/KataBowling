#include "catch.hpp"
#include "FrameInterpreter.h"


TEST_CASE("Score Interpreter raw input interpretations", "[score][interpreter]")
{
	REQUIRE(FrameInterpreter::interpret('G', '-').GetScore() == 0);
	REQUIRE(FrameInterpreter::interpret('G', '3').GetScore() == 3);
	REQUIRE(FrameInterpreter::interpret('G', '/').GetScore() == 10);

	REQUIRE(FrameInterpreter::interpret('3', '-').GetScore() == 3);
	REQUIRE(FrameInterpreter::interpret('3', '5').GetScore() == 8);
	REQUIRE(FrameInterpreter::interpret('3', '/').GetScore() == 10);

	REQUIRE(FrameInterpreter::interpret('X').GetScore() == 10);
}