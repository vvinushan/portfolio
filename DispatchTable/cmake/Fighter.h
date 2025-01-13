#pragma once

/*! \class Fighter
	\brief Base class used to derieve classes for each fighter
	\file Fighter.h
*/

// Includes string and iostream for use in this class and all derived classes
#include <string>
#include <iostream>

//! Base class Fighter
class Fighter {
	public:
		std::string fighterName; //!< Variable for name of the fighter
		float speed, resistance; //!< Variables for speed and resistance against damage
		float health; //!< Variable for health of the fighter
		float damage; //!< Variable for damage inflicted to opponent
	public:
		Fighter() {}; //!< Constructor
		~Fighter() {}; //!< Destructor

		Fighter(float speed, float resistance); //!< Overloading Fighter constructor
		void setName(std::string fighterName); //!< Function to set name of fighter
		void setHealth(float health); //!< Function to set fighter's health
		virtual float attack(); //!< Virtual function to attack, can be overridden by child classes
};