#pragma once

#include <SFML/Graphics.hpp>

#include "physicalThing.h"

class DynamicPendulum : public PhysicalThing, public sf::Drawable
{
private:
	sf::RectangleShape m_rectangle;
	b2Body * m_anchor;
	b2RevoluteJoint * m_hinge;
public:
	DynamicPendulum() {}; //!< Default constructor
	DynamicPendulum(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Color colour); // Full constructor
	DynamicPendulum(b2World * world, sf::Vector2f position, sf::Vector2f size, sf::Vector2f anchor, float orientation, sf::Texture * tex); // Full constructor
	void draw(sf::RenderTarget& render, sf::RenderStates states) const; //!< Draw shape
	void update();
};