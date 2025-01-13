#pragma once

#include "values.h"

class testingFixtures : public ::testing::Test {
public:
	Values* firstValues;
	Values* secondValues;
	int numbers[5] = { 0,1,2,3,10 };
	testingFixtures();
	void SetUp();
	void TearDown();
};