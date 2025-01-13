#include "pch.h"
#include <iostream>
#include <gtest/gtest.h>

//Runs all of the tests in the test.cpp file.
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}