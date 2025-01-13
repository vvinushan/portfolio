// Includes class header file
#include "HardNPC.h"

HardNPC::HardNPC(float speed, float resistance) //!< Constructor overloaded with speed and resistance
{
	this->speed = speed; // Pointing to variable speed
	this->resistance = resistance; // Pointing to variable resistance
}

HardNPC::HardNPC(float damage) //!< Constructor overloaded with damage
{
	this->damage = damage; // Pointing to variable damage
}

void HardNPC::setDifficulty(std::string difficulty) //!< Function to set difficulty to string difficulty
{
	this->difficulty = difficulty; // Pointing to variable difficulty
}

float HardNPC::attack() //!< OVerrides virtual function in base class
{
	this->damage = speed + (resistance * 1.5); // Increases damage from the original value in Fighter class
	return damage; // Returns damage value
}
