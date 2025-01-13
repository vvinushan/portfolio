#pragma once

/*!
\file dynamicPentagon.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class DynamicPentagon
\brief A pentagon which can move, rotate and collide with stuff
*/

class DynamicPentagon : public sf::CircleShape, public PhysicalThing
{
private:
	sf::Clock clock;
	float activeTime = clock.getElapsedTime().asSeconds();
public:
	DynamicPentagon(b2World * world, const sf::Vector2f& position, const float radius, const float orientation, int vertices); //!< Complete contructor
	void update(); //!< Update rendering infomation 
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Overridden drawing methos to include line to allow users to see oreintation of the ball
};