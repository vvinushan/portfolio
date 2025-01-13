#include "BlockCircleContactListener.h"

void BlockCircleContactListener::BeginContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	std::pair<std::string, void *> dataA = *(std::pair<std::string, void *>*) bodyA->GetUserData();
	std::pair<std::string, void *> dataB = *(std::pair<std::string, void *>*) bodyB->GetUserData();

	bool isSensorA = contact->GetFixtureA()->IsSensor();
	bool isSensorB = contact->GetFixtureB()->IsSensor();

	if (isSensorA)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyA->GetUserData());
		sensor->action();
		return;
	}

	if (isSensorB)
	{
		StaticSensor * sensor = static_cast<StaticSensor *>(bodyB->GetUserData());
		sensor->action();
		return;
	}

	if (typeid(StaticBlock).name() == dataA.first)
	{
		if (typeid(DynamicCircle).name() == dataB.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Cyan);
		}
		if (typeid(DynamicPentagon).name() == dataB.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Cyan);
		}
	}

	if (typeid(StaticBlock).name() == dataB.first)
	{
		if (typeid(DynamicCircle).name() == dataA.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
		if (typeid(DynamicPentagon).name() == dataA.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
	}

	if (typeid(DynamicBlock).name() == dataA.first)
	{
		if (typeid(DynamicCircle).name() == dataB.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
		if (typeid(DynamicPentagon).name() == dataB.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
	}

	if (typeid(DynamicBlock).name() == dataB.first)
	{
		if (typeid(DynamicCircle).name() == dataA.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Cyan);
		}
		if (typeid(DynamicPentagon).name() == dataA.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Cyan);
		}
	}
}

void BlockCircleContactListener::EndContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	std::pair<std::string, void *> dataA = *(std::pair<std::string, void *>*) bodyA->GetUserData();
	std::pair<std::string, void *> dataB = *(std::pair<std::string, void *>*) bodyB->GetUserData();

	if (typeid(StaticBlock).name() == dataA.first)
	{
		if (typeid(DynamicCircle).name() == dataB.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
		if (typeid(DynamicPentagon).name() == dataB.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
	}

	if (typeid(StaticBlock).name() == dataB.first)
	{
		if (typeid(DynamicCircle).name() == dataA.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
		if (typeid(DynamicPentagon).name() == dataA.first)
		{
			StaticBlock * block = static_cast<StaticBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Magenta);
		}
	}

	if (typeid(DynamicBlock).name() == dataA.first)
	{
		if (typeid(DynamicCircle).name() == dataB.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Red);
		}
		if (typeid(DynamicPentagon).name() == dataB.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataA.second);
			if (block != nullptr) block->setFillColor(sf::Color::Red);
		}
	}

	if (typeid(DynamicBlock).name() == dataB.first)
	{
		if (typeid(DynamicCircle).name() == dataA.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Red);
		}
		if (typeid(DynamicPentagon).name() == dataA.first)
		{
			DynamicBlock * block = static_cast<DynamicBlock*>(dataB.second);
			if (block != nullptr) block->setFillColor(sf::Color::Red);
		}
	}
}