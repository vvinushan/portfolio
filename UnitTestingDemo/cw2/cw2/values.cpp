#include "pch.h"
#include "values.h"

Values::Values(int xIn, int yIn)
{
	x = xIn;
	y = yIn; // Defining x and y
}

int Values::getX()
{
	return x; // Returns x
}

int Values::getY()
{
	return y; // Returns y
}
