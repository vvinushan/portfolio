#include "..\include\Multithreading.h" // Include class header file

//using namespace std::literals::chrono_literals;

Multithreading::Multithreading(int repeatNumber)
{ // Pointers
	this->RepeatNumber = repeatNumber;
	this->i = i;
	this->j = j;
	this->OriginalFile = OriginalFile;
	this->NewFile = NewFile;
}

void Multithreading::Message1(int i)
{
	const std::lock_guard<std::mutex> lock(LockGuard); // lock_guard to own this mutex and destroy outside of scope
	while (i < RepeatNumber) // While loop to continue thread until completion
	{
		std::cout << "Are you real?" << std::endl;
		std::this_thread::sleep_for(2s);
		i++;
	}
}

void Multithreading::Message2(int j)
{
	const std::lock_guard<std::mutex> lock(LockGuard); // lock_guard to own this mutex and destroy outside of scope
	while (j < RepeatNumber) // While loop
	{
		std::cout << "Can you see me?" << std::endl;
		std::this_thread::sleep_for(3s);
		j++;
	}
}

// Boolean function used to read originalFile and output to newFile
bool Multithreading::LoadFiles(std::string OriginalFile, std::string NewFile)
{
	std::ifstream LoadIn(OriginalFile); // Load originalFile into LoadIn
	std::vector<std::vector<std::string>> VectorFields; // Create vector for storing each line

	std::ofstream MyFile;
	MyFile.open(NewFile, std::ofstream::out | std::ofstream::trunc); // Open newFile to write

	if (LoadIn) // If statement when originalFile is loaded
	{
		std::string Line; // Declare new string variable Line

		// Process each line of originalFile and input into vector using while loops
		while (std::getline(LoadIn, Line))
		{
			std::stringstream sep(Line);
			std::string Field;

			VectorFields.push_back(std::vector<std::string>());

			while (getline(sep, Field, ','))
			{
				VectorFields.front().push_back(Field); // Front of vector
			}

		}
	}

	// Write each line of originalFile into a single column in newFile
	if (MyFile.is_open())
	{
		for (auto row : VectorFields) // For loop and nested for loop to write until all data is complete
		{
			for (auto field : row)
			{
				MyFile << field << " , " << std::endl; // Format to output into newFile
			}
		}
	}
	std::cout << "File complete" << std::endl; // Prints once function is complete

	return true; // Returns true
}
