#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Frame.h"


TEST_CASE("Testing Frame Scores", "[score][frame]")
{
	SECTION("Zero Frame Score")
	{
		auto testFrame = new Frame(0, 0);
		CHECK(testFrame->GetScore() == 0);
	}

	SECTION("5 Frame Score")
	{
		auto testFrame = new Frame(2, 3);
		CHECK(testFrame->GetScore() == 5);
	}
}


TEST_CASE("Testing Strike or Spare Frames", "[score][frame]")
{
	
}