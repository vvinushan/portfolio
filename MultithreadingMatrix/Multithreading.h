/**
@file Multithreading.h
*/

#pragma once

// Includes for use in Multithreading.cpp and Main.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <fstream>
#include <sstream>

// Namespace for Multithreading.cpp and Main.cpp
using namespace std::literals::chrono_literals;

class Multithreading {
	public: // Variables for use in class
		int RepeatNumber;
		int i;
		int j;
		std::mutex LockGuard;
		std::string OriginalFile;
		std::string NewFile;

	public: // Constructor, functions to demonstrate threads and boolean function to load csv input/output file
		Multithreading(int RepeatNumber);
		void Message1(int i);
		void Message2(int j);
		bool LoadFiles(std::string OriginalFile, std::string NewFile);
};