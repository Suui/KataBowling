#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Frame.h"

TEST_CASE("Building a Frame", "[frame]")
{
	SECTION("Creates a Frame without knocks")
		REQUIRE(Frame({'-', '-'}).knocks() == 0);
}