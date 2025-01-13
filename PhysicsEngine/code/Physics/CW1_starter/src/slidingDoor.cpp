#include "slidingDoor.h"

SlidingDoor::SlidingDoor(b2World * world, sf::Vector2f position, float angle)
{
	m_fMotionTime = 1.5f;
	m_state = CLOSED;

	b2BodyDef l_bodyDef;
	b2PolygonShape l_shape;
	b2FixtureDef l_fixtureDef;

	l_bodyDef.position.Set(position.x, position.y);

	m_body = world->CreateBody(&l_bodyDef);
	m_leftSide = world->CreateBody(&l_bodyDef);
	m_rightSide = world->CreateBody(&l_bodyDef);
	m_leftDoor = world->CreateBody(&l_bodyDef);
	m_rightDoor = world->CreateBody(&l_bodyDef);

	l_fixtureDef.density = mk_fDensity;
	l_fixtureDef.friction = mk_fFriction;
	l_fixtureDef.restitution = mk_fRestitution;
	l_fixtureDef.shape = &l_shape;

	l_shape.m_radius = 0.0f;

	l_shape.SetAsBox(0.5f * 0.5f, 0.16f * 0.5f, b2Vec2(-0.25f, 0.f), 0.f);
	m_leftDoor->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(-0.85f, -0.10f), 0.f);
	m_leftSide->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(-0.85f, 0.10f), 0.f);
	m_leftSide->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.18f * 0.5f, 0.18f * 0.5f, b2Vec2(-1.11f, 0.f), 0.f);
	m_leftSide->CreateFixture(&l_fixtureDef);

	l_shape.SetAsBox(0.5f * 0.5f, 0.16f * 0.5f, b2Vec2(0.25f, 0.f), 0.f);
	m_rightDoor->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(0.85f, -0.10f), 0.f);
	m_rightSide->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(0.85f, 0.10f), 0.f);
	m_rightSide->CreateFixture(&l_fixtureDef);
	l_shape.SetAsBox(0.18f * 0.5f, 0.18f * 0.5f, b2Vec2(1.11f, 0.f), 0.f);
	m_rightSide->CreateFixture(&l_fixtureDef);

	m_leftDoor->SetType(b2BodyType::b2_dynamicBody);
	b2MotorJointDef jointDef;
	jointDef.Initialize(m_leftSide, m_leftDoor);
	jointDef.maxForce = 1000.0f; // Force much large than we'd ever need
	jointDef.maxTorque = 1000.0f; // Avoid rotation with high torque
	m_leftMotor = (b2MotorJoint*) world->CreateJoint(&jointDef);

	m_rightDoor->SetType(b2BodyType::b2_dynamicBody);
	jointDef.Initialize(m_rightSide, m_rightDoor);
	jointDef.maxForce = 1000.0f; // Force much large than we'd ever need
	jointDef.maxTorque = 1000.0f; // Avoid rotation with high torque
	m_rightMotor = (b2MotorJoint*)world->CreateJoint(&jointDef);

	m_side1.setPosition(sf::Vector2f(m_leftSide->GetPosition().x-0.85, m_leftSide->GetPosition().y));
	m_side1.setSize(sf::Vector2f(0.7f,0.2f));
	m_side1.setOrigin(m_side1.getSize() * 0.5f);
	m_side1.setFillColor(sf::Color(60,60,60));
	m_side1.setOutlineThickness(0.f);

	m_side2.setPosition(sf::Vector2f(m_leftSide->GetPosition().x + 0.85, m_leftSide->GetPosition().y));
	m_side2.setSize(sf::Vector2f(0.7f, 0.2f));
	m_side2.setOrigin(m_side1.getSize() * 0.5f);
	m_side2.setFillColor(sf::Color(60, 60, 60));
	m_side2.setOutlineThickness(0.f);

	m_door1.setPosition(sf::Vector2f(m_leftDoor->GetFixtureList()->GetAABB(0).GetCenter().x, m_leftDoor->GetPosition().y));
	m_door1.setSize(sf::Vector2f(0.5f, 0.16f));
	m_door1.setOrigin(m_door1.getSize() * 0.5f);
	m_door1.setFillColor(sf::Color(90, 45, 0));
	m_door1.setOutlineThickness(0.f);

	m_door2.setPosition(sf::Vector2f(m_rightDoor->GetFixtureList()->GetAABB(0).GetCenter().x, m_rightDoor->GetPosition().y));
	m_door2.setSize(sf::Vector2f(0.5f, 0.16f));
	m_door2.setOrigin(m_door1.getSize() * 0.5f);
	m_door2.setFillColor(sf::Color(90, 45, 0));
	m_door2.setOutlineThickness(0.f);
}

void SlidingDoor::update(float timestep)
{
	if (m_state == OPENING)
	{
		m_fElapsedTime += timestep;
		float t = m_fElapsedTime / m_fMotionTime;
		float dist;
		
		if (t < 1.0f)
		{
			dist = t * -0.5f;
		}
		else
		{
			dist = -0.5f;
			m_state = OPEN;
		}

		m_leftMotor->SetLinearOffset(b2Vec2(dist, 0));
		m_rightMotor->SetLinearOffset(b2Vec2(-dist, 0));
	}

	if (m_state == CLOSING)
	{
		m_fElapsedTime += timestep;
		float t = m_fElapsedTime / m_fMotionTime;
		float dist;

		if (t < 1.0f)
		{
			dist = (1.0f-t) * -0.5f;
		}
		else
		{
			dist = 0.0f;
			m_state = CLOSED;
		}

		m_leftMotor->SetLinearOffset(b2Vec2(dist, 0));
		m_rightMotor->SetLinearOffset(b2Vec2(-dist, 0));
	}
	m_door1.setPosition(sf::Vector2f(m_leftDoor->GetFixtureList()->GetAABB(0).GetCenter().x, m_leftDoor->GetPosition().y));
	m_door2.setPosition(sf::Vector2f(m_rightDoor->GetFixtureList()->GetAABB(0).GetCenter().x, m_rightDoor->GetPosition().y));

}

void SlidingDoor::open()
{
	if (m_state == CLOSED)
	{
		m_fElapsedTime = 0.f;
		m_state = OPENING;
	}

	if (m_state == CLOSING)
	{
		m_fElapsedTime = m_fMotionTime - m_fElapsedTime;
		m_state = OPENING;
	}
}

void SlidingDoor::close()
{
	if (m_state == OPEN)
	{
		m_fElapsedTime = 0.f;
		m_state = CLOSING;
	}

	if (m_state == OPENING)
	{
		m_fElapsedTime = m_fMotionTime - m_fElapsedTime;
		m_state = CLOSING;
	}
}

void SlidingDoor::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_door1);
	target.draw(m_door2);
	target.draw(m_side1);
	target.draw(m_side2);
}
