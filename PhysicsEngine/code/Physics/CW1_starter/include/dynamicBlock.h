#pragma once

/*!
\file dynamicBlock.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "physicalThing.h"

/*! \class DynamicBlock
\brief A simple block which can move, rotate and collide with stuff
*/

class DynamicBlock : public sf::RectangleShape, public PhysicalThing
{
public:
	DynamicBlock(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation); //!< Complete contructor
	void update(); //!< Update rendering infomation 
};