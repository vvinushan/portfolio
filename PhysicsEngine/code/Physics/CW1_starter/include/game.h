#pragma once

/*!
\file game.h
*/

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

#include "staticBlock.h"
#include "dynamicBlock.h"
#include "dynamicCircle.h"
#include "slidingDoor.h"
#include "openDoorSensor.h"
#include "closeDoorSensor.h"
#include "doorPressureSensor.h"
#include "rotatingDoor.h"
#include "dynamicPendulum.h"
#include "SensorContactListener.h"
#include "ray.h"

#include "SFMLDebugDraw.h"

#define _USE_MATH_DEFINES
#include <math.h>

/*! \class Game
\brief Holds all information about the game, blocks, balls etc and allows updating and rendering.
*/

class Game : public sf::Drawable {
private:
	sf::View m_view; //!< The view maps from physical co-ordinates to rendering co-ordinates
	sf::Vector2f m_worldSize = sf::Vector2f(8.f, 6.f); //!< Size of the physical worlds is 8 X 6 metres

	b2World* m_pWorld = nullptr; //!< Pointer to the Box2D world.  Using pointers as BOX2D has it's own memory management
	const int mk_iVelIterations = 7; //!< On each update there will be 7 velocity iterations in the physics engine
	const int mk_iPosIterations = 5; //!< On each update there will be 5 position iterations on each update
	const b2Vec2 mk_gravity = b2Vec2(0.f, 0.f); //!< No gravity - top down view

	std::vector<StaticBlock> m_staticBlocks; //!< A collection of fixed blocks. 
	DynamicCircle m_ball; //!< A moving ball.
	DynamicCircle m_extraBall1; //!< A moving ball.
	DynamicCircle m_extraBall2; //!< A moving ball.
	DynamicCircle m_extraBall3; //!< A moving ball.
	DynamicCircle m_extraBall4; //!< A moving ball.
	DynamicCircle m_extraBall5; //!< A moving ball.
	DynamicCircle m_extraBall6; //!< A moving ball.
	DynamicCircle m_extraBall7; //!< A moving ball.
	DynamicCircle m_extraBall8; //!< A moving ball.
	DynamicCircle m_extraBall9; //!< A moving ball.
	DynamicCircle m_extraBall10; //!< A moving ball.
	Ray m_ray; //!< A ray in the direction of the ball
	float m_ballDirection; //!< Angle heading to fire the ball in radians
	float m_blockMoveX; //!< Direction for pressure sensor to move X
	float m_blockMoveY; //!< Direction for pressure sensor to move Y
	float m_blockRotation; //!< Rotation of pressure sensor
	SlidingDoor m_door; //!< A sliding door with timer
	OpenDoorSensor m_open; //!< Sensor for opening a sliding door
	CloseDoorSensor m_close; //!< Sensor for closing a sliding door
	doorPressureSensor m_pressure; //!< Prssure sensor linked to the sliding door
	RotatingDoor m_rotatingDoor; //!< Rotating door
	DynamicPendulum m_dynamicPendulum;

	SensorContactListener m_listener; //!< Contact listener for collisions
	bool m_debug = false; //!< Toggle for debug drawing
	SFMLDebugDraw m_debugDraw; //!< Box2D debug drawing
	void toggleDebug() { m_debug = !m_debug; } //!< Toggle for debug drawing
public:
	Game(); //!< Constructor which sets up the game
	~Game(); //!< Destructor which cleans all the pointer memory up
	void update(float timestep); //!< Update the game with give timestep
	void draw(sf::RenderTarget &target, sf::RenderStates states) const; //!< Draw the game to the render context
	void processKeyPress(sf::Keyboard::Key code); //!< Process user key press

};
