/**
@file main.cpp
*/


/*! \mainpage Fighter Game Dispatch Table
 *
 * Implementation of a dispatch table for a fighter game
 */

// Includes iostream and all classes
#include <iostream>
#include "Fighter.h"
#include "Player.h"
#include "EasyNPC.h"
#include "HardNPC.h"

int main() /** Entry point for the application */
{
	// Initialise and set values for Player 1
	Player P1(100.f, 100.f);
	P1.setName("Player 1");
	P1.setHealth(100);
	
	// Initialise and set values for Ken (Easy enemy)
	EasyNPC E1(50.f, 50.f);
	E1.setName("Ken");
	E1.setHealth(50);
	E1.setDifficulty("Easy");

	// Initialise and set values for Akuma (Hard enemy)
	HardNPC H1(150.f, 150.f);
	H1.setName("Akuma");
	H1.setHealth(150);
	H1.setDifficulty("Hard");

	// Using dynamic casting to output Player 1's attributes
	Fighter &downCastP1 = P1;
	Player *downCastPlayer = dynamic_cast<Player*>(&downCastP1);
	std::cout << "Fighter's name is " << downCastPlayer->fighterName << std::endl;
	std::cout << downCastPlayer->fighterName << "'s speed is " << downCastPlayer->speed << std::endl;
	std::cout << downCastPlayer->fighterName << "'s resistance is " << downCastPlayer->resistance << std::endl;
	std::cout << downCastPlayer->fighterName << "'s health is " << downCastP1.health << std::endl;

	// Using upcasting to output Player 1's damage value
	Fighter* P1Upcast;
	P1Upcast = &P1;
	std::cout << "Player's attack damage is: " << P1Upcast->attack() << std::endl;

	// Empty line
	std::cout << " " << std::endl;

	// Using dynamic casting to output Ken's attributes
	Fighter &downCastE1 = E1;
	EasyNPC *downCastEasyNPC = dynamic_cast<EasyNPC*>(&downCastE1);
	std::cout << "Enemy's name is " << downCastEasyNPC->fighterName << std::endl;
	std::cout << downCastEasyNPC->fighterName << "'s difficulty is " << downCastEasyNPC->difficulty << std::endl;
	std::cout << downCastEasyNPC->fighterName << "'s speed is " << downCastEasyNPC->speed << std::endl;
	std::cout << downCastEasyNPC->fighterName << "'s resistance is " << downCastEasyNPC->resistance << std::endl;
	std::cout << downCastEasyNPC->fighterName << "'s health is " << downCastEasyNPC->health << std::endl;

	// Using upcasting to output Ken's damage value
	Fighter* E1Upcast;
	E1Upcast = &E1;
	std::cout << downCastEasyNPC->fighterName << "'s attack damage is " << E1Upcast->attack() << std::endl;

	// Empty line
	std::cout << " " << std::endl;

	// Using dynamic casting to output Akuma's attributes
	Fighter &downCastH1 = H1;
	HardNPC *downCastHardNPC = dynamic_cast<HardNPC*>(&downCastH1);
	std::cout << "Enemy's name is " << downCastHardNPC->fighterName << std::endl;
	std::cout << downCastHardNPC->fighterName << "'s difficulty is " << downCastHardNPC->difficulty << std::endl;
	std::cout << downCastHardNPC->fighterName << "'s speed is " << downCastHardNPC->speed << std::endl;
	std::cout << downCastHardNPC->fighterName << "'s resistance is " << downCastHardNPC->resistance << std::endl;
	std::cout << downCastHardNPC->fighterName << "'s health is " << downCastHardNPC->health << std::endl;

	// Using upcasting to output Akuma's damage value
	Fighter* H1Upcast;
	H1Upcast = &H1;
	std::cout << downCastHardNPC->fighterName << "'s attack damage is " << H1Upcast->attack() << std::endl;

	system("pause"); // Pause
	return 0; // Returns 0
};