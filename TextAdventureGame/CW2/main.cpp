#include "Enemy.h"
#include "json.hpp"
#include "Objects.h"
#include "Rooms.h"
#include <fstream>
#include <iostream>

int main() {
	std::ifstream fin("map3.json");
	nlohmann::json j; // object that represents the json data
	fin >> j; // read from file into j

	// Containers for objectives 'what' from JSON
	std::vector<std::string> winEnemies;
	std::vector<std::string> winObjects;
	std::vector<std::string> readRoom;
	std::string winRoom;

	// If statements to read in objective type and what from JSON
	if (j["objective"]["type"].get<std::string>() == "kill")
		winEnemies = j["objective"]["what"].get<std::vector<std::string>>();
	else if (j["objective"]["type"].get<std::string>() == "collect")
		winObjects = j["objective"]["what"].get<std::vector<std::string>>();
	else if (j["objective"]["type"].get<std::string>() == "room")
	{
		readRoom = j["objective"]["what"].get<std::vector<std::string>>();
		winRoom = readRoom[0];
		readRoom.clear();
	}

	// Containers to output and string to store input. List and vector are cleared after each use.
	std::vector<std::string> vectorOutputs;
	std::list<std::string> listOutputs;
	std::string command;

	// Initialise class objects for use
	Rooms myRoom(j);
	Objects myObject(j);
	Enemy myEnemy(j);

	// Output room description
	std::cout << myRoom.getDesc() << std::endl;

	// Get and output initital room objects from list, if any
	listOutputs = myObject.getRoomObjects();

	if (listOutputs.empty() != true)
	{
		std::cout << "This room has the following objects: " << std::endl;
		for (std::string listOutput : listOutputs)
			std::cout << listOutput << std::endl;
		listOutputs.clear();
	}

	// Get enemy details in initial room, if any
	if (myEnemy.getEnemy() != "")
	{
		vectorOutputs.push_back(myEnemy.getEnemy());
		vectorOutputs.push_back(myEnemy.getDesc());
	}

	// Output enemy details in initial room, if any
	if (vectorOutputs.empty() != true)
	{
		std::cout << "There is an enemy in this room: " << std::endl;
		std::cout << vectorOutputs[0] << std::endl;
		std::cout << vectorOutputs[1] << std::endl;
		vectorOutputs.clear();
	}

	// While loop for main game coding. While loop will be continuous, program will exit if main function returns exit code 0 at any point
	bool objective = false;
	while (objective == false)
	{
		std::getline(std::cin, command); // Read player input

		if (command == "look" || command == "look around") // Look at current room, output details
		{
			std::cout << "You are at " << myRoom.getCurrentRoom() << std::endl;

			std::cout << myRoom.getDesc() << std::endl;

			listOutputs = myObject.getRoomObjects();

			if (listOutputs.empty() != true)
			{
				std::cout << "" << std::endl;
				std::cout << "This room has the following objects: " << std::endl;
				for (std::string listOutput : listOutputs)
					std::cout << listOutput << std::endl;
				listOutputs.clear();
			}

			if (myEnemy.getEnemy() != "")
			{
				vectorOutputs.push_back(myEnemy.getEnemy());
				vectorOutputs.push_back(myEnemy.getDesc());
			}

			if (vectorOutputs.empty() != true)
			{
				std::cout << "" << std::endl;
				std::cout << "There is an enemy in this room: " << vectorOutputs[0] << std::endl;
				std::cout << vectorOutputs[1] << std::endl;
				vectorOutputs.clear();
			}
		}
		else if (command.find("go ") != std::string::npos) // Go to an exit to another room
		{
			command.erase(0, 3); // Removes 'go ' and keeps necessary data

			// Player moves room only if they specified a valid exit
			if (myRoom.updateRoom(command))
			{
				// If enemy is in current room and not killed before moving, this handles enemy attack
				if ((myEnemy.getEnemy().empty() != true) && (myEnemy.willAttack() == true))
				{
					std::cout << "The enemy attacks you as you are leaving and succeeds in killing you. Game over." << std::endl;
					return 0;
				}
				else if ((myEnemy.getEnemy().empty() != true))
					std::cout << "The enemy attacks you as you are leavimg but fails to kill you. You have used the exit." << std::endl;

				std::cout << myRoom.getDesc() << std::endl; // New room description output

				// If player is trapped with no way to achieve objective, game will end and exit code 0 returned
				if (winRoom != myRoom.getCurrentRoom() && winRoom.empty() != true)
				{
					if (myRoom.isTrapped())
					{
						std::cout << "There is no way out. Game over." << std::endl;
						return 0;
					}
				}
				else if (winRoom == myRoom.getCurrentRoom()) // If objective is to reach room
				{
					std::cout << "You have won the game!" << std::endl;
					return 0;
				}

				// Updates new room objects and outputs all (minus those in inventory, handled in Objects class)
				myObject.updateRoomObjects(myRoom.getCurrentRoom());
				listOutputs = myObject.getRoomObjects();
				if (listOutputs.empty() != true)
				{
					std::cout << "" << std::endl;
					std::cout << "This room has the following objects: " << std::endl;
					for (std::string listOutput : listOutputs)
						std::cout << listOutput << std::endl;
					listOutputs.clear();
				}

				// Update new room enemy if any, if enemy has been killed it will not be output (handled in Enemy class)
				myEnemy.updateEnemy(myRoom.getCurrentRoom());
				if (myEnemy.getEnemy() != "")
				{
					vectorOutputs.push_back(myEnemy.getEnemy());
					vectorOutputs.push_back(myEnemy.getDesc());
				}

				if (vectorOutputs.empty() != true)
				{
					std::cout << "" << std::endl;
					std::cout << "There is an enemy in this room: " << vectorOutputs[0] << std::endl;
					std::cout << vectorOutputs[1] << std::endl;
					vectorOutputs.clear();
				}
			}
			else
				std::cout << "That exit does not exist." << std::endl;
		}
		else if ((command.find("look ") != std::string::npos) && (command != "look around")) // Look at object for description
		{
			command.erase(0, 5); // Removes 'look ' and keeps object name specified by player

			std::cout << myObject.getObjectDesc(command) << std::endl;
		}
		else if ((command.find("take ") != std::string::npos)) // Take object in room and add to inventory
		{
			command.erase(0, 5); // Removes 'take ' and keeps object name specified by player

			// Check if enemy is dead or non-existent before adding object to inventory
			if (myEnemy.getEnemy().empty() == true)
			{
				if (myObject.updateInventory(command)) // Check if object is valid
				{
					std::cout << command << " has been added to your inventory." << std::endl;

					// Check if the objective is to collect and if it has been achieved
					if (winObjects.empty() != true)
					{
						int objectCount = 0;
						std::vector<std::string> objectsTaken = myObject.getInventory();
						for (int i = 0; i < winObjects.size(); i++)
						{
							for (int j = 0; j < objectsTaken.size(); j++)
							{
								if (winObjects[i] == objectsTaken[j])
									objectCount++;
							}
						}

						if (objectCount == winObjects.size())
						{
							std::cout << "You have won the game!" << std::endl;
							return 0;
						}
						else if (myRoom.isTrapped() && objectCount != winObjects.size()) // If player is trapped and objective not achieved, game over
						{
							std::cout << "You are trapped and you don't have all of the required objects. Game over." << std::endl;
							return 0;
						}
					}
				}
				else
					std::cout << "Error: object not found in room or is already in your inventory." << std::endl;
			}
			else
				std::cout << "You need to kill the enemy first before you can try to take an object." << std::endl;
		}
		else if (command == "list items") // Outputs items in inventory
		{
			vectorOutputs = myObject.getInventory();
			if (vectorOutputs.empty() != true)
			{
				std::cout << "You have the following objects in your inventory: " << std::endl;
				for (int i = 0; i < vectorOutputs.size(); i++)
					std::cout << vectorOutputs[i] << std::endl;
				vectorOutputs.clear();
			}
			else
			{
				std::cout << "Your inventory is empty." << std::endl;
			}
		}
		else if ((command.find("kill ") != std::string::npos)) // Kill enemy with objects
		{
			command.erase(0, 5); // Removes 'kill ' and keeps enemy name as specified by player

			// Check if enemy exists in current room and there's no typo
			if (command == myEnemy.getEnemy())
			{
				std::vector<std::string> inventory = myObject.getInventory();
				std::vector<std::string> killObjects = myEnemy.getKillObjects();
				int killObjectCount = 0;

				// Determine if inventory has the rewuired objects to kill enemy using integer counts
				for (int i = 0; i < inventory.size(); i++)
				{
					for (int j = 0; j < killObjects.size(); j++)
					{
						if (inventory[i] == killObjects[j])
							killObjectCount++;
					}
				}

				if (killObjectCount == killObjects.size())
				{
					myEnemy.updateKill(command);
					std::cout << "You have killed the " << command << std::endl;

					if (winEnemies.empty() != true)
					{
						int killCount = 0;
						std::vector<std::string> killedEnemies = myEnemy.getKilledEnemies();
						for (int i = 0; i < winEnemies.size(); i++)
						{
							for (int j = 0; j < killedEnemies.size(); j++)
							{
								if (winEnemies[i] == killedEnemies[j])
									killCount++;
							}
						}

						// Check if objective is complete and if not, check if player is trapped
						if (killCount == winEnemies.size())
						{
							std::cout << "You have won the game!" << std::endl;
							return 0;
						}
						else if (myRoom.isTrapped() && killCount != winEnemies.size())
						{
							std::cout << "You are trapped and you haven't kill all of the required enemies. Game over." << std::endl;
							return 0;
						}
					}
				}
				else
				{
					std::cout << "You couldn't kill as you didn't have the required objects. Enemy has killed you. Game over." << std::endl;
					return 0;
				}
			}
			else
				std::cout << "That enemy does not exist in this room." << std::endl;
		}
	}
}