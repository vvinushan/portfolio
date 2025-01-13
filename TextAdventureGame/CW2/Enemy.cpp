#include "Enemy.h"

Enemy::Enemy(nlohmann::json mapFile)
{
	m_mapFile = mapFile;

	m_initialRoom = m_mapFile["player"]["initialroom"].get<std::string>();

	for (int i = 0; i < m_mapFile["enemies"].size(); i++)
	{
		if (m_mapFile["enemies"][i]["initialroom"].get<std::string>() == m_initialRoom) // Check if enemy is in initial room and updates properties
		{
			m_enemy = m_mapFile["enemies"][i]["id"].get<std::string>();
			
			m_desc = m_mapFile["enemies"][i]["desc"].get<std::string>();

			agg = m_mapFile["enemies"][i]["aggressiveness"].get<int>();

			m_killObjects = m_mapFile["enemies"][i]["killedby"].get<std::vector<std::string>>();
		}
	}
}

std::string Enemy::getEnemy()
{
	return m_enemy;
}

std::string Enemy::getDesc()
{
	return m_desc;
}

std::vector<std::string> Enemy::getKillObjects()
{
	return m_killObjects;
}

std::vector<std::string> Enemy::getKilledEnemies()
{
	return m_killedEnemies;
}

void Enemy::updateEnemy(std::string room)
{
	// Clears and updates vector if enemy is in new room and not killed
	m_enemy = "";
	m_desc = "";

	m_killObjects.clear();

	m_initialRoom = room;

	for (int i = 0; i < m_mapFile["enemies"].size(); i++)
	{
		if (m_mapFile["enemies"][i]["initialroom"].get<std::string>() == m_initialRoom)
		{
			m_enemy = m_mapFile["enemies"][i]["id"].get<std::string>();

			if (std::find(m_killedEnemies.begin(), m_killedEnemies.end(), m_enemy) != m_killedEnemies.end())
				m_enemy = "";
			else
			{
				m_desc = m_mapFile["enemies"][i]["desc"].get<std::string>(); // Update description

				agg = m_mapFile["enemies"][i]["aggressiveness"].get<int>();

				m_killObjects = m_mapFile["enemies"][i]["killedby"].get<std::vector<std::string>>();
			}
		}
	}
}

void Enemy::updateKill(std::string enemy)
{
	// Updates vector if enemy is killed
	m_killedEnemies.push_back(enemy);

	m_enemy = "";
	m_desc = "";
}

bool Enemy::willAttack()
{
	// Player kill chance determined by random number and probability of aggressiveness
	if (agg == 0)
		return false;
	else
	{
		int randomNum = rand() % 100 + 1;
		if (randomNum < agg)
			return true;
		else
			return false;
	}
}
