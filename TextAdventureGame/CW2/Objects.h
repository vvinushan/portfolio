#pragma once

#include "json.hpp"
#include <algorithm>
#include <list>
#include <string>
#include <vector>

class Objects
{
private:
	
	// JSON data set in constructor
	nlohmann::json m_mapFile;

	// Current object
	std::string m_object;

	// Current object description
	std::string m_desc;

	// Object's initial room
	std::string m_initialRoom;

	// List of objects in room
	std::list<std::string> m_roomObjects; // List for efficient erasing of items anywhere in list after object added to inventory

	// Vector of objects in inventory
	std::vector<std::string> m_inventory;

public:
	
	// Constructor sets up objects in intital room
	Objects(nlohmann::json mapFile);

	// Return list of objects in current room (by using Rooms m_currentroom getter in main.cpp) after checking inventory
	std::list<std::string> getRoomObjects();

	// Return inventory vector
	std::vector<std::string> getInventory();

	// Get current object description
	std::string getObjectDesc(std::string object);

	// When object is picked up after checking roomObjects list and removed from roomObjects
	bool updateInventory(std::string object);

	// Update room objects when player moves
	void updateRoomObjects(std::string room);
};

