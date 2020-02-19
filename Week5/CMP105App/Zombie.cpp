#include "Zombie.h"

Zombie::Zombie()
{
	speed = 100;
	
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Zombie::~Zombie()
{

}

void Zombie::update(float dt) 
{
	//walk.animate(dt);
	//setTextureRect(walk.getCurrentFrame());

	if(input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		setTextureRect(currentAnimation->getCurrentFrame());

		currentAnimation->animate(dt);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (getPosition().x > 0) move(-(speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (getPosition().x < _winsize.x-getSize().x) move((speed * dt), 0);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (getPosition().y > 0) move(0, -(speed * dt));
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (getPosition().y < _winsize.y-getSize().y) move(0, (speed * dt));
	}
}

void Zombie::getWin(sf::Vector2u winsize)
{
	_winsize = winsize;
}