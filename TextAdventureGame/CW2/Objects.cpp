#include "Objects.h"

Objects::Objects(nlohmann::json mapFile)
{
	m_mapFile = mapFile;

	m_initialRoom = m_mapFile["player"]["initialroom"].get<std::string>();

	for (int i = 0; i < m_mapFile["objects"].size(); i++)
	{
		if (m_mapFile["objects"][i]["initialroom"].get<std::string>() == m_initialRoom) // Finds objects in current room
		{
			m_object = m_mapFile["objects"][i]["id"].get<std::string>();
			m_roomObjects.push_back(m_object);
		}
	}
}

std::list<std::string> Objects::getRoomObjects()
{
	return m_roomObjects;
}

std::vector<std::string> Objects::getInventory()
{
	return m_inventory;
}

std::string Objects::getObjectDesc(std::string object)
{
	// Check if object is in inventory or in current room by iterating through vectors
	if ((std::find(m_inventory.begin(), m_inventory.end(), object) != m_inventory.end()) || std::find(m_roomObjects.begin(), m_roomObjects.end(), object) != m_roomObjects.end())
	{
		for (int i = 0; i < m_mapFile["objects"].size(); i++)
		{
			if (m_mapFile["objects"][i]["id"].get<std::string>() == object)
			{
				m_desc = m_mapFile["objects"][i]["desc"].get<std::string>();
				return m_desc;
			}
		}
	}
	else
	{
		std::string errorMessage = "Error: object does not wxist in room or inventory.";
		return errorMessage;
	}
}

bool Objects::updateInventory(std::string object)
{
	// Check if taken object is in current room by iterating through vector
	if (std::find(m_roomObjects.begin(), m_roomObjects.end(), object) != m_roomObjects.end())
	{
		m_inventory.push_back(object);

		std::list<std::string>::iterator it = std::find(m_roomObjects.begin(), m_roomObjects.end(), object);
		m_roomObjects.erase(it);
		return true;
	}
	else
		return false;
}

void Objects::updateRoomObjects(std::string room)
{
	// Clears and updates vector with new room objects if any
	m_initialRoom = room;
	m_roomObjects.clear();

	for (int i = 0; i < m_mapFile["objects"].size(); i++)
	{
		if (m_mapFile["objects"][i]["initialroom"].get<std::string>() == m_initialRoom)
		{
			m_object = m_mapFile["objects"][i]["id"].get<std::string>();

			if (std::find(m_inventory.begin(), m_inventory.end(), m_object) == m_inventory.end())
				m_roomObjects.push_back(m_object);
		}
	}
}
