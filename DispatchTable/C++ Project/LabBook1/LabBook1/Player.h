#pragma once

/*! \class Player
	\brief A derived class used for the playable fighter
	\file Player.h
*/

// Includes base class Fighter
#include "Fighter.h"

//! Player class is derived from base class Fighter
class Player : public Fighter {
	protected:
		float health; //!< Health of the player
	public:
		Player(float speed, float resistance); //!< Overriding class constructor with speed and resistance
		Player(float damage); //!< Overriding class constructor with damage
};