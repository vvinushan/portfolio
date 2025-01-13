/*!
\file game.cpp
*/
#include "game.h"

Game::Game()
{
	m_view.setCenter(0.f, 0.f);
	m_view.setSize(m_worldSize);

	m_pWorld = new b2World(mk_gravity);

	m_debugDraw.setWorld(m_pWorld);

	// Simple box to keep the ball in bounds
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(-4.f, 0.f), sf::Vector2f(0.1f, 6.0f), 0.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(4.f, 0.0f), sf::Vector2f(0.1f, 6.0f), 0.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, -3.f), sf::Vector2f(8.0f, 0.1f), 0.f));
	m_staticBlocks.push_back(StaticBlock(m_pWorld, sf::Vector2f(0.f, 3.f), sf::Vector2f(8.0f, 0.1f), 0.f));

	m_ballDirection = 0.0f;
	m_blockMoveX = 2.5f;
	m_blockMoveY = -2.5f;
	m_blockRotation = 45.f;
	m_ball = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, -2.f), 0.08f, m_ballDirection);
	m_ray = Ray(m_pWorld, 20.f, sf::Color::Magenta);
	m_door = SlidingDoor(m_pWorld, sf::Vector2f(0.5, -0.5), 0.f);
	m_open = OpenDoorSensor(m_pWorld, sf::Vector2f(0.5f, -1.0f), sf::Vector2f(0.3f * 0.5f, 0.3f * 0.5f), 0.f, &m_door);
	m_open.setUserData(&m_open);
	m_close = CloseDoorSensor(m_pWorld, sf::Vector2f(0.5f, 0.f), sf::Vector2f(0.3f * 0.5f, 0.3f * 0.5f), 0.f, &m_door);
	m_close.setUserData(&m_close);
	m_rotatingDoor = RotatingDoor(m_pWorld, sf::Vector2f(-2.f, -1.f), sf::Vector2f(1.f, 0.08f), sf::Vector2f(0.f, 0.f), 0.f, sf::Color::Blue);
	m_dynamicPendulum = DynamicPendulum(m_pWorld, sf::Vector2f(2.f, 1.f), sf::Vector2f(0.25f, 0.5f), sf::Vector2f(0.f, 0.5f), 0.f, sf::Color());
	m_dynamicPendulum.setUserData(&m_dynamicPendulum);

	m_extraBall1 = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 1.f), 0.08f, 0.0f);
	m_extraBall2 = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 0.8f), 0.08f, 0.0f);
	m_extraBall3 = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 0.6f), 0.08f, 0.0f);
	m_extraBall4 = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 0.4f), 0.08f, 0.0f);
	m_extraBall5 = DynamicCircle(m_pWorld, sf::Vector2f(-1.5f, 0.2f), 0.08f, 0.0f);
	m_extraBall6 = DynamicCircle(m_pWorld, sf::Vector2f(-2.f, 1.f), 0.08f, 0.0f);
	m_extraBall7 = DynamicCircle(m_pWorld, sf::Vector2f(-2.f, 0.8f), 0.08f, 0.0f);
	m_extraBall8 = DynamicCircle(m_pWorld, sf::Vector2f(-2.f, 0.6f), 0.08f, 0.0f);
	m_extraBall9 = DynamicCircle(m_pWorld, sf::Vector2f(-2.f, 0.4f), 0.08f, 0.0f);
	m_extraBall10 = DynamicCircle(m_pWorld, sf::Vector2f(-2.f, 0.2f), 0.08f, 0.0f);

	m_pWorld->SetContactListener(&m_listener);
}

Game::~Game()
{
	// Clean up all pointers
	delete m_pWorld;
	m_pWorld = nullptr;
}

void Game::update(float timestep)
{
	// Update the world
	m_pWorld->Step(timestep, mk_iVelIterations, mk_iVelIterations);

	// Update each dyanmic element - effectively update render information
	m_ball.update();
	m_extraBall1.update();
	m_extraBall2.update();
	m_extraBall3.update();
	m_extraBall4.update();
	m_extraBall5.update();
	m_extraBall6.update();
	m_extraBall7.update();
	m_extraBall8.update();
	m_extraBall9.update();
	m_extraBall10.update();

	m_door.update(timestep);

	m_rotatingDoor.update();

	if (m_ball.isStopped()) {
		m_ray.setDirection(m_ballDirection);
		m_ray.cast(m_ball.getPosition());
	}

	m_pressure = doorPressureSensor(m_pWorld, sf::Vector2f(m_blockMoveX, m_blockMoveY), sf::Vector2f(0.6f * 0.5f, 0.6f * 0.5f), m_blockRotation, &m_door);
	m_pressure.setUserData(&m_pressure);

	m_dynamicPendulum.update();

	// Delete debug shapes
	if (m_debug) m_debugDraw.clear();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(m_view);

	// Draw everything
	if (m_ball.isStopped()) target.draw(m_ray);

	for (StaticBlock block : m_staticBlocks) target.draw(block);

	target.draw(m_rotatingDoor);

	if (!m_debug) target.draw(m_door);

	target.draw(m_open);
	target.draw(m_close);
	target.draw(m_pressure);

	target.draw(m_ball);
	target.draw(m_extraBall1);
	target.draw(m_extraBall2);
	target.draw(m_extraBall3);
	target.draw(m_extraBall4);
	target.draw(m_extraBall5);
	target.draw(m_extraBall6);
	target.draw(m_extraBall7);
	target.draw(m_extraBall8);
	target.draw(m_extraBall9);
	target.draw(m_extraBall10);

	target.draw(m_dynamicPendulum);

	// Debug Draw
	if (m_debug) target.draw(m_debugDraw);
}

void Game::processKeyPress(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
	case sf::Keyboard::Space:
		if (m_ball.isStopped()) m_ball.applyImpulse(b2Vec2(0.05f * cosf(m_ballDirection), 0.05f * sinf(m_ballDirection)));
		break;
	case sf::Keyboard::Right:
		m_ballDirection += 0.05f;
		if (m_ballDirection > 2.0f * M_PI) m_ballDirection -= 2.0f * M_PI;
		break;
	case sf::Keyboard::Left:
		m_ballDirection -= 0.05f;
		if (m_ballDirection < 0.0f) m_ballDirection += 2.0f * M_PI;
		break;
	case sf::Keyboard::W:
		m_blockMoveY -= 0.05f;
		break;
	case sf::Keyboard::A:
		m_blockMoveX -= 0.05f;
		break;
	case sf::Keyboard::S:
		m_blockMoveY += 0.05f;
		break;
	case sf::Keyboard::D:
		m_blockMoveX += 0.05f;
		break;
	case sf::Keyboard::R:
		m_blockRotation += 5.f;
		break;
	case sf::Keyboard::T:
		m_blockRotation -= 5.f;
		break;
	}
}

