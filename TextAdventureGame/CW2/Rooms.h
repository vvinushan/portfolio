#pragma once

#include "json.hpp"
#include <map>
#include <string>
#include <vector>

class Rooms
{
private:

	// JSON data set in constructor
	nlohmann::json m_mapFile;

	// Current room
	std::string m_currentRoom;

	// Current room description
	std::string m_desc;

	// Map of exits from current room
	std::map<std::string, std::string> m_exitMaps;

public:

	// Constructor sets up initial room properties, takes in map file data from main.cpp (command line argument)
	Rooms(nlohmann::json mapFile);

	// Updates new room properties if valid exit input
	bool updateRoom(std::string input);

	// Getter for current room description
	std::string getDesc();

	// Getter for current room
	std::string getCurrentRoom();

	// Check if player is trapped with no exits
	bool isTrapped();
};

