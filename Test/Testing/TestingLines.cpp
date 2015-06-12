#include "../TestRunner/catch.hpp"
#include "../../Source/Line.h"


TEST_CASE("Checking Line Scores", "[line][Score]")
{
	SECTION("Creates an all zeroes Line")
		CHECK(Line("--------------------").Score() == 0);

	SECTION("Creates a line with some knocks")
		CHECK(Line("-3--23--------------").Score() == 8);

	SECTION("Calculates Score for a line with a spare")
		CHECK(Line("-3--23--3/4---------").Score() == 26);

	SECTION("Calculates Score for a line with a spare and a strike")
		CHECK(Line("-3--23--3/4-X35----").Score() == 52);

	SECTION("Calculates Score for a line with two consecutive strikes")
		CHECK(Line("--XX--------------").Score() == 30);

	SECTION("Calculates Score for a line with two consecutive spares")
		CHECK(Line("--3/5/--------------").Score() == 25);

	SECTION("Calculates Score for a line with a spare followed by a strike")
		CHECK(Line("----8/X------------").Score() == 30);

	SECTION("Calculates Score for a line with three consecutive strikes")
		CHECK(Line("----XXX----------").Score() == 60);

	SECTION("Calculates Score for a line with a spare in the last frame")
		CHECK(Line("------------------4/2").Score() == 12);

	SECTION("Calculates Score for a line with a strike in the last frame")
		CHECK(Line("------------------X22").Score() == 14);

	SECTION("Calculates Score for a line with a strike and a spare in the last frame")
		CHECK(Line("------------------X2/").Score() == 20);

	SECTION("Calculates Score for a line with a spare and a strike in the last frame")
		CHECK(Line("------------------2/X").Score() == 20);

	SECTION("Calculates Score for a line with two strikes last frame")
		CHECK(Line("------------------XX2").Score() == 22);

	SECTION("Calculates Score for a line with three strikes last frame")
		CHECK(Line("------------------XX2").Score() == 22);

	SECTION("Calculates Score for all strikes")
		CHECK(Line("XXXXXXXXXXXX").Score() == 300);

	SECTION("Calculates Score for all spares")
		CHECK(Line("5/5/5/5/5/5/5/5/5/5/5").Score() == 150);
}