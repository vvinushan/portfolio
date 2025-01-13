#pragma once

#include "json.hpp"
#include <stdlib.h>
#include <string>
#include <vector>

class Enemy
{
private:
	
	// JSON data set in constructor
	nlohmann::json m_mapFile;

	// Current enemy name
	std::string m_enemy;

	// Current enemy description
	std::string m_desc;

	// Current enemy aggressiveness
	int agg;

	// Initial room of enemy
	std::string m_initialRoom;

	// Vector of objects that can kill enemy
	std::vector<std::string> m_killObjects;

	// Vector of enemies that have been killed in current game
	std::vector<std::string> m_killedEnemies;

public:
	
	// Constructor sets up enemies in player initial room
	Enemy(nlohmann::json mapFile);

	// Get enemy name
	std::string getEnemy();

	// Get enemy description
	std::string getDesc();

	// Get vector of objects that can kill enemy
	std::vector<std::string> getKillObjects();

	// Get vector of enemies that have been killed in current game
	std::vector<std::string> getKilledEnemies();

	// Update enemy when going to another room if any
	void updateEnemy(std::string room);

	// Update vector of enemy killed
	void updateKill(std::string enemy);

	// Enemy attack success based on aggressiveness
	bool willAttack();
};

