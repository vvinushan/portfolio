#include "pch.h"
#include "calc.h"
#include "testingFixtures.h"
#include <gtest/gtest.h>

// Two different test groups: fatal and non-fatal assertions

TEST(Fatal, TrueTest) // Fatal
{
	calc test;
	ASSERT_TRUE(20, test.add(10, 10)); // Deliminted by comma
	std::cout << "Has output. Fatal assertion" << std::endl;
}

TEST(NonFatal, TrueTest) // Non-fatal
{
	calc test;
	EXPECT_TRUE(30, test.add(5, 10)); // Deliminted by comma
	std::cout << "Has output. Non-fatal assertion" << std::endl;
}

TEST(Fatal, FalseTest) // Fatal
{
	calc test;
	ASSERT_FALSE(10, test.sub(30, 10)); // Deliminted by comma
	std::cout << "Has output. Fatal assertion" << std::endl;
}

TEST(NonFatal, FalseTest) // Non-fatal
{
	calc test;
	EXPECT_FALSE(20, test.sub(30, 10)); // Deliminted by comma
	std::cout << "Has output. Non-fatal assertion" << std::endl;
}

/////////////////

TEST(Fatal, EqualTest) // Fatal
{
	calc test;
	ASSERT_EQ(20, test.sub(30, 10)); // Deliminted by comma. Test to see if 20 is equal to (30+10)
}

TEST(NonFatal, EqualTest) // Non-fatal
{
	calc test;
	EXPECT_EQ(test.add(15, 20), test.sub(5, 2)); // Deliminted by comma. Test to see if (15+20) is equal to (5-2)
}

TEST(Fatal, NotEqualTest) // Fatal
{
	calc test;
	ASSERT_NE(test.add(20, 20), 50); // Deliminted by comma. Test to see if (20+20) is not equal to 50
}

TEST(NonFatal, NotEqualTest) // Non-fatal
{
	calc test;
	EXPECT_NE(test.sub(50, 10), test.mult(2, 10)); // Deliminted by comma. Test to see if (50+10) is not equal to (2x10)
}

TEST(Fatal, LowerThanTest) // Fatal
{
	calc test;
	ASSERT_LT(15, test.mult(15, 1)); // Deliminted by comma. Test to see if 15 is lower than (15x1)
}

TEST(NonFatal, LowerThanTest) // Non-fatal
{
	calc test;
	EXPECT_LT(test.add(15, 1), 15); // Deliminted by comma. Test to see if (15+1) is lower than 15
}

TEST(Fatal, GreaterThanTest) // Fatal
{
	calc test;
	ASSERT_GT(test.mult(30, 30), test.mult(90, 90)); // Deliminted by comma. Test to see if (30x30) is greater than (90x90)
}

TEST(NonFatal, GreaterThanTest) // Non-fatal
{
	calc test;
	EXPECT_GT(test.mult(90, 90), test.mult(30, 30)); // Deliminted by comma. Test to see if (90x90) is greater than (30x30)
}

///////////////////////////////

TEST(NonFatal, IterationTest) // Non-fatal
{
	calc test;
	for (int i = 1; i <= 10; i++) // Tests across multiple values
	{
		EXPECT_TRUE(i, test.add(10, 20)); // Deliminted by comma
		std::cout << "Multiple values. Non-fatal assertion" << std::endl;
	}
}

TEST(Fatal, IterationTest) // Fatal
{
	calc test;
	for (int i = 1; i <= 10; i++) // Tests across multiple values
	{
		ASSERT_TRUE(i, test.dot_product({ 3, 2, 1 }, {1.f, 2.f, 3.f})); // Deliminted by comma
		std::cout << "Dot product. Fatal assertion" << std::endl;
	}	
}

///////////////////////////////

TEST(Fatal, EqualStringTest) // Fatal
{
	calc test;
	ASSERT_STRCASEEQ(test.concatString("Add", "ition").data(), "addition"); // Deliminted by comma. Non-case sensitive string comparison
}

TEST(NonFatal, EqualCaseStringTest) // Non-fatal
{
	calc test;
	EXPECT_STREQ(test.concatString("Add", "ition").data(), "addition"); // Deliminted by comma. Case sensitive string comparison
}

////////////////////////////////

TEST_F(testingFixtures, Test1) // Non-fatal testing fixture
{
	EXPECT_EQ(50, firstValues->getX()); // Deliminted by comma. Test if 50 is equal to value of x in firstValues (50)
}

TEST_F(testingFixtures, Test2) // Non-fatal testing fixture
{
	EXPECT_GT(70, secondValues->getY()); // Deliminted by comma. Test if 70 is greater than value of y in secondValues (65)
}

TEST_F(testingFixtures, Test3) // Non-fatal testing fixture
{
	for (int i = 0; i < 5; i++) // Test runs until i < 5
	{
		EXPECT_GE(numbers[i], i); // Deliminted by comma. Test if data in numbers at [i] is greater or equal to value of i
	}
}