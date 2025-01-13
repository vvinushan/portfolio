#include "Enemy.h"
#include "json.hpp"
#include "Objects.h"
#include "Rooms.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {

	std::ifstream fin(argv[1]);
	if (argc == 1)
	{
		std::cerr << "Must execute with map file." << std::endl;
		return 0;
	}
	else if (argc > 2)
	{
		std::cerr << "Incorrect command. Please execute with a map file, only one map file may be used at a time." << std::endl;
		return 0;
	}
	nlohmann::json j; // object that represents the json data
	fin >> j; // read from file into j

	std::vector<std::string> winEnemies;
	std::vector<std::string> winObjects;
	std::vector<std::string> readRoom;
	std::string winRoom;

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

	std::vector<std::string> vectorOutputs;
	std::list<std::string> listOutputs;
	std::string command;

	Rooms myRoom(j);
	Objects myObject(j);
	Enemy myEnemy(j);

	std::cout << myRoom.getDesc() << std::endl;

	listOutputs = myObject.getRoomObjects();

	if (listOutputs.empty() != true)
	{
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
		std::cout << "There is an enemy in this room: " << std::endl;
		std::cout << vectorOutputs[0] << std::endl;
		std::cout << vectorOutputs[1] << std::endl;
		vectorOutputs.clear();
	}

	bool objective = false;
	while (objective == false)
	{
		std::getline(std::cin, command);

		if (command == "look" || command == "look around") // Look at current room
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
			if ((myEnemy.getEnemy().empty() != true) && (myEnemy.willAttack() == true))
			{
				std::cout << "The enemy attacks you as you are leaving and succeeds in killing you. Game over." << std::endl;
				return 0;
			}
			else if ((myEnemy.getEnemy().empty() != true))
				std::cout << "The enemy attacks you as you are leavimg but fails to kill you. You have used the exit." << std::endl;
			
			command.erase(0, 3);
			
			myRoom.updateRoom(command);
			std::cout << myRoom.getDesc() << std::endl;

			if (winRoom != myRoom.getCurrentRoom() && winRoom.empty() != true)
			{
				if (myRoom.isTrapped())
				{
					std::cout << "There is no way out. Game over." << std::endl;
					return 0;
				}
			}
			else if (winRoom == myRoom.getCurrentRoom())
			{
				std::cout << "You have won the game!" << std::endl;
				return 0;
			}

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
		else if ((command.find("look ") != std::string::npos) && (command != "look around")) // Look at object for desc
		{
			command.erase(0, 5);
			
			std::cout << myObject.getObjectDesc(command) << std::endl;
		}
		else if ((command.find("take ") != std::string::npos))
		{
			command.erase(0, 5);
			
			if (myEnemy.getEnemy().empty() == true)
			{
				if (myObject.updateInventory(command))
				{
					std::cout << command << " has been added to your inventory." << std::endl;

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
						else if (myRoom.isTrapped() && objectCount != winObjects.size())
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
		else if (command == "list items")
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
		else if ((command.find("kill ") != std::string::npos))
		{
			command.erase(0, 5);

			std::vector<std::string> inventory = myObject.getInventory();
			std::vector<std::string> killObjects = myEnemy.getKillObjects();
			int killObjectCount = 0;

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
	}
}