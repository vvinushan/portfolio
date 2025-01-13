#pragma once

/*! \class EasyNPC
	\brief A derived class used for the easy difficulty NPC
	\file EasyNPC.h
*/

// Includes base class Fighter
#include "Fighter.h"

//! EasyNPC class derived from base class Fighter
class EasyNPC : public Fighter {
	public:
		std::string difficulty; //!< String variable difficulty
	public:
		EasyNPC(float speed, float resistance); //!< Constructor overloaded with variables speed and resistance
		EasyNPC(float damage); //!< Constructor overloaded with variable damage
		void setDifficulty(std::string difficulty); //!< Function to set difficulty to string difficulty
		float attack() override; //!< OVerrides virtual function in base class
};