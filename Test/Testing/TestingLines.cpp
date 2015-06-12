#include "../TestRunner/catch.hpp"
#include "../../Source/Line.h"


TEST_CASE("Checking Line Scores", "[line][score]")
{
	SECTION("Creates an all zeroes Line")
		CHECK(Line("--------------------").score() == 0);

	SECTION("Creates a line with some knocks")
		CHECK(Line("-3--23--------------").score() == 8);

	SECTION("Calculates score for a line with a spare")
		CHECK(Line("-3--23--3/4---------").score() == 26);

	SECTION("Calculates score for a line with a spare and a strike")
		CHECK(Line("-3--23--3/4-X35----").score() == 52);

	SECTION("Calculates score for a line with two consecutive strikes")
		CHECK(Line("--XX--------------").score() == 30);

	SECTION("Calculates score for a line with two consecutive spares")
		CHECK(Line("--3/5/--------------").score() == 25);

	SECTION("Calculates score for a line with a spare followed by a strike")
		CHECK(Line("----8/X------------").score() == 30);

	SECTION("Calculates score for a line with three consecutive strikes")
		CHECK(Line("----XXX----------").score() == 60);

	SECTION("Calculates score for a line with a spare in the last frame")
		CHECK(Line("------------------4/2").score() == 12);

	SECTION("Calculates score for a line with a strike in the last frame")
		CHECK(Line("------------------X22").score() == 14);

	SECTION("Calculates score for a line with a strike and a spare in the last frame")
		CHECK(Line("------------------X2/").score() == 20);

}