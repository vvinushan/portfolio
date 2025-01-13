#include "pch.h"
#include "testingFixtures.h"

testingFixtures::testingFixtures()
{
	firstValues = new Values(50, 55); // x = 50, y = 55
	secondValues = new Values(55, 60); // x = 55, y = 60
}

void testingFixtures::SetUp()
{
	// All code
}

void testingFixtures::TearDown()
{
	delete firstValues;
	delete secondValues; // Clears memory
}
