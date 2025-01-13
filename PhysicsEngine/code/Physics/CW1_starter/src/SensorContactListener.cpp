#include "SensorContactListener.h"

void SensorContactListener::BeginContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	bool isSensorA = contact->GetFixtureA()->IsSensor();
	bool isSensorB = contact->GetFixtureB()->IsSensor();

	if (isSensorA)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyA->GetUserData());
		sensor->onAction(bodyB);
		sensor->setFillColor(sf::Color::Cyan);
		return;
	}

	if (isSensorB)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyB->GetUserData());
		sensor->onAction(bodyA);
		sensor->setFillColor(sf::Color::Magenta);
		return;
	}
}

void SensorContactListener::EndContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	bool isSensorA = contact->GetFixtureA()->IsSensor();
	bool isSensorB = contact->GetFixtureB()->IsSensor();

	if (isSensorA)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyA->GetUserData());
		sensor->offAction(bodyB);
		sensor->setFillColor(sf::Color::Cyan);
		return;
	}

	if (isSensorB)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyB->GetUserData());
		sensor->offAction(bodyA);
		sensor->setFillColor(sf::Color::Magenta);
		return;
	}
}

