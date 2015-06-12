#include "../TestRunner/catch.hpp"
#include "../../Source/Frame.h"
#include "../../Source/FrameParser.h"


TEST_CASE("Building a Frame", "[frame]")
{
	SECTION("Creates a Frame without knocks")
		REQUIRE(FrameParser().Parse({ '-', '-' }).Knocks() == 0);

	SECTION("Creates a Frame with some knocks")
	{
		REQUIRE(FrameParser().Parse({ '-', '3' }).Knocks() == 3);
		REQUIRE(FrameParser().Parse({ '4', '4' }).Knocks() == 8);
	}

	SECTION("Creates a Frame with a spare")
	{
		REQUIRE(FrameParser().Parse({ '-', '/' }).Knocks() == 10);
		REQUIRE(FrameParser().Parse({ '3', '/' }).Knocks() == 10);
	}

	SECTION("Creates a Frame with a strike")
		REQUIRE(FrameParser().Parse({ 'X' }).Knocks() == 10);

	SECTION("Calculates knocks for a last Frame with a spare")
	{
		REQUIRE(FrameParser().Parse({ '3', '/', 'X' }).Knocks() == 10);
		REQUIRE(FrameParser().Parse({ '3', '/', 'X' }).Bonus() == 10);
	}

	SECTION("Calculates knocks for a last Frame with a strike")
	{
		REQUIRE(FrameParser().Parse({ 'X', '3', '5' }).Knocks() == 10);
		REQUIRE(FrameParser().Parse({ 'X', '3', '5' }).Bonus() == 8);
	}

	SECTION("Calculates knocks for a last Frame with and a spare")
	{
		REQUIRE(FrameParser().Parse({ 'X', '3', '/' }).Knocks() == 10);
		REQUIRE(FrameParser().Parse({ 'X', '3', '/' }).Bonus() == 10);
	}
}


TEST_CASE("Checking what a Frame is", "[frame]")
{
	SECTION("Frame knows it is a Spare")
		REQUIRE(FrameParser().Parse({ '-', '/' }).IsSpare());

	SECTION("Frame knows it is a Strike")
		REQUIRE(FrameParser().Parse({ 'X' }).IsStrike());
}