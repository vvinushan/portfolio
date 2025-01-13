#include "doorPressureSensor.h"

doorPressureSensor::doorPressureSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door)
{
	initRectangle(world, position, size, orientation);
	m_door = door;
	setFillColor(sf::Color(0, 80, 0));
}

void doorPressureSensor::onAction(b2Body * other)
{
	setFillColor(sf::Color(0, 255, 0));
	m_door->open();
}

void doorPressureSensor::offAction(b2Body * other)
{
	setFillColor(sf::Color(0, 80, 0));
	m_door->close();
}

