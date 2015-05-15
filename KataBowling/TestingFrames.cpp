#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Frame.h"

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

}