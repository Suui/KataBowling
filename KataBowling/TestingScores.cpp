#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Frame.h"


TEST_CASE("Testing Frame Scores", "[score][frame]")
{
	SECTION("Zero Frame Score")
	{
		auto TestFrame = new Frame(0, 0);
		CHECK(TestFrame->GetScore() == 0);
	}

	SECTION("5 Frame Score")
	{
		auto TestFrame = new Frame(2, 3);
		CHECK(TestFrame->GetScore() == 5);
	}
}


TEST_CASE("Testing Strike or Spare Frames", "[score][frame]")
{
	auto SpareFrame = new Frame(0, 10);
	auto StrikeFrame = new Frame(10, 0);

	CHECK(SpareFrame->IsSpare());
	CHECK(StrikeFrame->IsStrike());
}