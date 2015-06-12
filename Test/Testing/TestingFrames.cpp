#include "../TestRunner/catch.hpp"
#include "../../Source/Frame.h"


TEST_CASE("Building a Frame", "[frame]")
{
	SECTION("Creates a Frame without knocks")
		REQUIRE(Frame({ '-', '-' }).knocks() == 0);

	SECTION("Creates a Frame with some knocks")
	{
		REQUIRE(Frame({ '-', '3' }).knocks() == 3);
		REQUIRE(Frame({ '4', '4' }).knocks() == 8);
	}

	SECTION("Creates a Frame with a spare")
	{
		REQUIRE(Frame({ '-', '/' }).knocks() == 10);
		REQUIRE(Frame({ '3', '/' }).knocks() == 10);
	}

	SECTION("Creates a Frame with a strike")
		REQUIRE(Frame({ 'X' }).knocks() == 10);
}


TEST_CASE("Checking what a Frame is", "[frame]")
{
	SECTION("Frame knows it is a Spare")
		REQUIRE(Frame({ '-', '/' }).isSpare());

	SECTION("Frame knows it is a Strike")
		REQUIRE(Frame({ 'X' }).isStrike());
}