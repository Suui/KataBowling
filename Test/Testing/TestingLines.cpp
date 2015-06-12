#include "../TestRunner/catch.hpp"
#include "../../Source/Line.h"


TEST_CASE("Checking Line Scores", "[line][score]")
{
	SECTION("Creates an all zeroes Line")
		REQUIRE(Line("--------------------").score() == 0);

	SECTION("Creates a line with some knocks")
		REQUIRE(Line("-3--23--------------").score() == 8);

	SECTION("Calculates score for a line with a spare")
		REQUIRE(Line("-3--23--3/4---------").score() == 26);

	SECTION("Calculates score for a line with a spare and a strike")
		REQUIRE(Line("-3--23--3/4-X35----").score() == 52);

	SECTION("Calculates score for a line with two consecutive strikes")
		REQUIRE(Line("--XX--------------").score() == 30);
}