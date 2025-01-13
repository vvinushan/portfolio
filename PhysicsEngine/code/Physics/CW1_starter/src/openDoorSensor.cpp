#pragma once

#include "openDoorSensor.h"

OpenDoorSensor::OpenDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door)
{
	initRectangle(world, position, size, orientation);
	m_door = door;
	setFillColor(sf::Color(0, 200, 0));
}

void OpenDoorSensor::onAction(b2Body * other)
{
	m_door->open();
}
