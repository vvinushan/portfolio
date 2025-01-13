#pragma once

/*! \class HardNPC
	\brief A derived class used for the harder difficulty NPC
	\file HardNPC.h
*/

// Includes base class Fighter
#include "Fighter.h"

//! HardNPC class is derived from base class Fighter
class HardNPC : public Fighter {
	public:
		std::string difficulty; //!< String variable difficulty
	public:
		HardNPC(float speed, float resistance); //!< Constructor overloaded with variables speed and resistance
		HardNPC(float damage); //!< Constructor overloaded with variable damage
		void setDifficulty(std::string difficulty); //!< Function to set difficulty to string difficulty
		float attack() override; //!< OVerrides virtual function in base class
};