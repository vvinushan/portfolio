#pragma once

#pragma once

#include "staticSensor.h"
#include "slidingDoor.h"

class doorPressureSensor : public StaticSensor
{
private:

public:
	doorPressureSensor() {}; //!< Default constructor
	doorPressureSensor(b2World * world, sf::Vector2f position,sf::Vector2f size, float orientation, SlidingDoor * door);
	void onAction(b2Body * other);
	void offAction(b2Body * other);
	SlidingDoor * m_door;
};