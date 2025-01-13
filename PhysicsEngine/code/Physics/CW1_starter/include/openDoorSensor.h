#pragma once

#include "staticSensor.h"
#include "slidingDoor.h"

class OpenDoorSensor : public StaticSensor
{
private:
	
public:
	OpenDoorSensor() {}; //!< Default constructor
	OpenDoorSensor(b2World * world, sf::Vector2f position, sf::Vector2f size, float orientation, SlidingDoor * door);
	void onAction(b2Body * other);
	void offAction(b2Body * other) {};
	SlidingDoor * m_door;
};