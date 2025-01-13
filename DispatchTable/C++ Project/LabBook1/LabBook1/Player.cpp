// Includes class header file
#include "Player.h"

Player::Player(float speed, float resistance) //!< Constructor overloaded with speed and resistance
{
	this->speed = speed; // Pointing to variable speed
	this->resistance = resistance; // Pointing to variable resistance
	std::cout << "Initialise Player" << std::endl; // Output to console
}
 
Player::Player(float damage) //!< Constructor overloaded with damage
{
	this->damage = damage; // Pointing to variable damage
}
