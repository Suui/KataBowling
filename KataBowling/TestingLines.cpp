#include "catch.hpp"
#include "Line.h"


TEST_CASE("Checking Line Scores", "[line][score]")
{
	SECTION("Creates an all zeroes Line")
		REQUIRE(Line("--------------------").score() == 0);

	SECTION("Creates a line with some knocks")
		REQUIRE(Line("-3--23--------------").score() == 8);
}