#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Frame.h"
#include "FrameInterpreter.h"
#include "Line.h"


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


TEST_CASE("Testing Strike, Spare and Last Frame", "[score][frame]")
{
	auto SpareFrame = new Frame(0, 10);
	auto StrikeFrame = new Frame(10, 0);
	auto LastFrame = new Frame(2, 2, 2);

	REQUIRE(SpareFrame->IsSpare());
	REQUIRE(StrikeFrame->IsStrike());
	REQUIRE(LastFrame->IsLastFrame());
}


SCENARIO("Testing score values for the Last Frame (plain sum)", "[score][frame]")
{
	GIVEN("A last frame score of 0, 0, 0")
	{
		auto LastFrame = new Frame(0, 0, 0);
		
		REQUIRE(LastFrame->IsLastFrame());
		CHECK(LastFrame->GetScore() == 0);
	}

	GIVEN("A last frame score of 0, 10, 10")
	{
		auto LastFrame = new Frame(0, 10, 10);
		
		REQUIRE(LastFrame->IsLastFrame());
		CHECK(LastFrame->GetScore() == 20);
	}

	GIVEN("A last frame score of 10, 10, 10")
	{
		auto LastFrame = new Frame(10, 10, 10);
		
		REQUIRE(LastFrame->IsLastFrame());
		CHECK(LastFrame->GetScore() == 30);
	}
}


TEST_CASE("Score Interpreter interpretations", "[score][interpreter]")
{
	REQUIRE(FrameInterpreter::interpret('G', '-').GetScore() == 0);
	REQUIRE(FrameInterpreter::interpret('G', '3').GetScore() == 3);
	REQUIRE(FrameInterpreter::interpret('G', '/').GetScore() == 10);
	
	REQUIRE(FrameInterpreter::interpret('3', '-').GetScore() == 3);
	REQUIRE(FrameInterpreter::interpret('3', '5').GetScore() == 8);
	REQUIRE(FrameInterpreter::interpret('3', '/').GetScore() == 10);

	REQUIRE(FrameInterpreter::interpret('X').GetScore() == 10);
}


TEST_CASE("Line score tests", "[score][line]")
{
	SECTION("All zeroes")
	{
		REQUIRE(Line("G-G-G-G-G-G-G-G-G-G-").GetScore() == 0);
	}

	SECTION("No Spares or Strikes")
	{
		REQUIRE(Line("G-36G4G-G-G-18G-9-9-").GetScore() == 40);
	}

	SECTION("A Spare")
	{

	}

	SECTION("A Strike")
	{

	}

	SECTION("A Spare and a Strike")
	{

	}

	SECTION("All Spares")
	{

	}

	SECTION("All Strikes")
	{

	}
}