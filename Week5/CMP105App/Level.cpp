#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombieSpriteWalk.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombieSpriteWalk);
	zombie.setInput(input);
	zombie.getWin(window->getSize());

	marioSpriteSheet.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(16, 20));
	mario.setPosition(300, 300);
	mario.setTexture(&marioSpriteSheet);
	mario.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	zombie.handleInput(dt);
	mario.update(dt);
	mario.handleInput(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zombie);
	window->draw(mario);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}