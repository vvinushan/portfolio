// Includes class header file
#include "Fighter.h"

Fighter::Fighter(float speed, float resistance) //!< Overloading class constructor
{
	this->speed = speed; // Pointing to the variable speed
	this->resistance = resistance; // Pointing to the variable resistance
}

void Fighter::setName(std::string fighterName) //!< Function to set the name of the fighter
{
	this->fighterName = fighterName; // Pointing to the string fighterName
}

void Fighter::setHealth(float health) //!< Function to set the health of the fighter
{
	this->health = health; // Pointing to the variable health
}

float Fighter::attack() //!< Virtual function for fighter to attack
{
	this->damage = speed + resistance; // Point to the damage value as speed + resistance
	return damage; // Return value of damage
}
