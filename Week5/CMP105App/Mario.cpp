#include "Mario.h"

#include "Zombie.h"

Mario::Mario()
{
	speed = 100;

	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	
	duck.addFrame(sf::IntRect(0, 41, 16, 20)); 
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	//walk.animate(dt);
	//setTextureRect(walk.getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::D))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	if ((input->isKeyDown(sf::Keyboard::X)) && (!currentAnimation->getFlipped()))
	{
		currentAnimation = &duck;
		currentAnimation->setFlipped(false);
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	if ((input->isKeyDown(sf::Keyboard::X)) && (currentAnimation->getFlipped()))
	{
		currentAnimation = &duck;
		currentAnimation->setFlipped(true);
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}

void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (getPosition().x > 0) move(-(speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (getPosition().x < _winsize.x - getSize().x) move((speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (getPosition().y > 0) move(0, -(speed * dt));
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (getPosition().y < _winsize.y - getSize().y) move(0, (speed * dt));
	}
}

void Mario::getWin(sf::Vector2u winsize)
{
	_winsize = winsize;
}