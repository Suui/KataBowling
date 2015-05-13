#include "catch.hpp"
#include  "Line.h"


TEST_CASE("Line score tests", "[score][line]")
{
	SECTION("All zeroes")
		REQUIRE(Line("G-G-G-G-G-G-G-G-G-G-").GetScore() == 0);

	SECTION("No Spares or Strikes")
		REQUIRE(Line("G-36G4G-G-G-18G-9-9-").GetScore() == 40);

	SECTION("A Spare")
		REQUIRE(Line("G-36G4G/3-G-18G-9-9-").GetScore() == 56);

	SECTION("A Strike")
		REQUIRE(Line("G-36G4G-X3-18G-9-9-").GetScore() == 66);

	SECTION("A Spare and a Strike")
		REQUIRE(Line("5/5-G-G/X5/3-G-G-3-").GetScore() == 89); // 10+5=15 +5=20 +10+10=40  +20+10=70 +10+3=83 +3=86 +3=89  [89]

	SECTION("Spare or Strike in the Last Frame")
	{
		REQUIRE(Line("G-G-G-G-G-G-G-G-G-G/G").GetScore() == 10);
		REQUIRE(Line("G-G-G-G-G-G-G-G-G-G/X").GetScore() == 20);
		REQUIRE(Line("G-G-G-G-G-G-G-G-G-XXX").GetScore() == 30);

		REQUIRE(Line("G-G-G-G-G-G-G-G-G/XXX").GetScore() == 50);
		REQUIRE(Line("G-G-G-G-G-G-G-G-XXXX").GetScore() == 60);
	}

	SECTION("All Spares")
	{
		REQUIRE(Line("G/G/G/G/G/G/G/G/G/G/G").GetScore() == 100);
		REQUIRE(Line("3/3/3/3/3/3/3/3/3/3/3").GetScore() == 130);
		REQUIRE(Line("5/5/5/5/5/5/5/5/5/5/5").GetScore() == 150);
	}

	SECTION("All Strikes")
		REQUIRE(Line("XXXXXXXXXXXX").GetScore() == 300);
}