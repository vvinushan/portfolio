#include "pch.h" //Needs to be first
#include "calc.h"
#include <numeric>


calc::calc() {}

//Addition function.
int calc::add(int i, int j)
{
	return i + j;
}

//Subtraction function.
int calc::sub(int i, int j)
{
	return i - j;
}

//Multiplication function.
float calc::mult(int i, int j)
{
	return (float)i * j;
}


std::string calc::concatString(std::string a, std::string b)
{
	return a + b;
}

//Dot product function.
//Reference https://en.cppreference.com/w/cpp/algorithm/inner_product and 
//https://stackoverflow.com/questions/61645527/how-can-i-do-a-dot-product-between-a-matrix-and-a-vector-in-c
double calc::dot_product(const std::vector<std::vector<int>>& e, const std::vector<float>& p)
{
	double result = 0;
	for (auto& v : e) //range based loop
		result += std::inner_product(v.begin(), v.end(), p.begin(), 0.0);
	return result;
}

