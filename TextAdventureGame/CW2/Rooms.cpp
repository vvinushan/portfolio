#include "Rooms.h"

Rooms::Rooms(nlohmann::json mapFile)
{
	m_mapFile = mapFile;

	m_currentRoom = m_mapFile["player"]["initialroom"].get<std::string>();
	
	for (int i = 0; i < m_mapFile["rooms"].size(); i++)
	{
		if (m_mapFile["rooms"][i]["id"].get<std::string>() == m_currentRoom)
		{
			m_desc = m_mapFile["rooms"][i]["desc"].get<std::string>(); // Update description

			for (auto e : m_mapFile["rooms"][i]["exits"].items()) { // Reads each exit and room then maps them
				std::string myKey = e.key();
				std::string myValue = e.value();
				m_exitMaps[myKey] = myValue;
			}
		}
	}
}

bool Rooms::updateRoom(std::string input)
{
	std::map<std::string, std::string>::iterator findIt = m_exitMaps.find(input);
	
	// Check if player has input valid exit
	if (findIt != m_exitMaps.end())
	{
		m_currentRoom = findIt->second;
	}
	else
		return false;

	m_exitMaps.clear();

	for (int i = 0; i < m_mapFile["rooms"].size(); i++)
	{
		if (m_mapFile["rooms"][i]["id"].get<std::string>() == m_currentRoom)
		{
			m_desc = m_mapFile["rooms"][i]["desc"].get<std::string>();

			for (auto e : m_mapFile["rooms"][i]["exits"].items()) { // Reads each exit and room then maps them
				std::string myKey = e.key();
				std::string myValue = e.value();
				m_exitMaps[myKey] = myValue;
			}
		}
	}
	return true;
}

std::string Rooms::getDesc()
{
	return m_desc;
}

std::string Rooms::getCurrentRoom()
{
	return m_currentRoom;
}

bool Rooms::isTrapped()
{
	if (m_exitMaps.empty() == true)
		return true;
	else
		return false;
}