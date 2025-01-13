#pragma once

#include "staticSensor.h"
#include "slidingDoor.h"

class CloseDoorSensor : public StaticSensor
{
private:

public:
	CloseDoorSensor() {}; //!< Default constructor
	CloseDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door);
	void onAction(b2Body * other);
	void offAction(b2Body * other) {};
	SlidingDoor * m_door;
};