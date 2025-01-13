#pragma once
#include<iostream>
#include<string>
#include <vector>
class calc {
public:
	calc(); // Default constructor
	int add(int i, int j); //Function for adding two int.
	int sub(int i, int j);  //Function for subtracting two int.
	float mult(int i, int j); //Function for multiplying two int with a float output.
	std::string concatString(std::string a, std::string b); //Function for forming a single string.
	double dot_product(const std::vector<std::vector<int>> &e, const std::vector<float> &p); //Function to calculate the dot product of two matrices.
};