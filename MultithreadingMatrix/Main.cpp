/**
@file Main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of Coursework Lab Book 3
 */

 // Includes Multithreading class header file
#include "Multithreading.h"

int Input; // Input value

int main() /** Entry point for the application */
{
	auto start = std::chrono::high_resolution_clock::now(); // Begin timing threads
	Multithreading MyThread(15); // Constructor

	std::thread first(&Multithreading::Message1, &MyThread, 0); // Spawn first thread
	std::thread second(&Multithreading::Message2, &MyThread, 0); // Spawn secon thread
	std::future<bool> third = std::async(&Multithreading::LoadFiles, &MyThread, "unigram_freq.csv", "Processed.csv"); // Calling 'LoadFiles' function asynchronously

	// Print to console and ask for input
	std::cout << "What do you believe?" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. This is reality" << std::endl;
	std::cout << "2. Reality is just a human construct and we are never really present anywhere" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Pick a number. Choose carefully: " << std::endl;
	std::cin >> Input; // Ask for input from user and store in 'Input'

	// If statements for each answer the user provides
	if (Input == 1)
	{
		std::cout << "A rational answer, well done." << std::endl;
	}
	else if (Input == 2)
	{
		std::cout << "You are willing to question everything, aren't you?" << std::endl;
	}
	else
	{
		std::cout << "Are you trying to trick me?!" << std::endl;
	}

	std::cout << "You will never know!" << std::endl;

	// Synchronising the threads
	first.join();
	second.join();

	auto end = std::chrono::high_resolution_clock::now(); // End timing threads
	double duration = (std::chrono::duration<double, std::milli>(end - start).count()); // Work out the total duration of threads

	std::cout << "Total duration: " << duration << " milliseconds." << std::endl; // Print duration to console

	return 0; // Returns 0
};