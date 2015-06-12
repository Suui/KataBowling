#include "../TestRunner/catch.hpp"
#include "../../Source/Line/LineBuilder.h"
#include "../../Source/Line/Line.h"


TEST_CASE("Checking Line Scores", "[line][Score]")
{
	SECTION("Creates an all zeroes Line")
		CHECK(LineBuilder::Build("--------------------").Score() == 0);

	SECTION("Creates a line with some knocks")
		CHECK(LineBuilder::Build("-3--23--------------").Score() == 8);

	SECTION("Calculates Score for a line with a spare")
		CHECK(LineBuilder::Build("-3--23--3/4---------").Score() == 26);

	SECTION("Calculates Score for a line with a spare and a strike")
		CHECK(LineBuilder::Build("-3--23--3/4-X35----").Score() == 52);

	SECTION("Calculates Score for a line with two consecutive strikes")
		CHECK(LineBuilder::Build("--XX--------------").Score() == 30);

	SECTION("Calculates Score for a line with two consecutive spares")
		CHECK(LineBuilder::Build("--3/5/--------------").Score() == 25);

	SECTION("Calculates Score for a line with a spare followed by a strike")
		CHECK(LineBuilder::Build("----8/X------------").Score() == 30);

	SECTION("Calculates Score for a line with three consecutive strikes")
		CHECK(LineBuilder::Build("----XXX----------").Score() == 60);

	SECTION("Calculates Score for a line with a spare in the last frame")
		CHECK(LineBuilder::Build("------------------4/2").Score() == 12);

	SECTION("Calculates Score for a line with a strike in the last frame")
		CHECK(LineBuilder::Build("------------------X22").Score() == 14);

	SECTION("Calculates Score for a line with a strike and a spare in the last frame")
		CHECK(LineBuilder::Build("------------------X2/").Score() == 20);

	SECTION("Calculates Score for a line with a spare and a strike in the last frame")
		CHECK(LineBuilder::Build("------------------2/X").Score() == 20);

	SECTION("Calculates Score for a line with two strikes last frame")
		CHECK(LineBuilder::Build("------------------XX2").Score() == 22);

	SECTION("Calculates Score for a line with three strikes last frame")
		CHECK(LineBuilder::Build("------------------XX2").Score() == 22);

	SECTION("Calculates Score for all strikes")
		CHECK(LineBuilder::Build("XXXXXXXXXXXX").Score() == 300);

	SECTION("Calculates Score for all spares")
		CHECK(LineBuilder::Build("5/5/5/5/5/5/5/5/5/5/5").Score() == 150);
}