// Includes class header file
#include "EasyNPC.h"

EasyNPC::EasyNPC(float speed, float resistance) //!< Constructor overloaded with speed and resistance
{
	this->speed = speed; // Pointing to variable speed
	this->resistance = resistance; // Pointing to variable resistance
}

EasyNPC::EasyNPC(float damage) //!< Constructor overloaded with damage
{
	this->damage = damage; // Pointing to variable damage
}

void EasyNPC::setDifficulty(std::string difficulty) //!< Function to set difficulty to string difficulty
{
	this->difficulty = difficulty; // Pointing to variable difficulty
}

float EasyNPC::attack() //!< OVerrides virtual function in base class
{
	this->damage = speed + (resistance * 0.5); // Decreases damage from original value in class Fighter
	return damage; // Returns damage value
}
