#pragma once

#include "closeDoorSensor.h"

CloseDoorSensor::CloseDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door)
{
	initRectangle(world, position, size, orientation);
	m_door = door;
	setFillColor(sf::Color(200, 0, 0));
}

void CloseDoorSensor::onAction(b2Body * other)
{
	m_door->close();
}
