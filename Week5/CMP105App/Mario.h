#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario :
	public GameObject
{
	int speed;
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt) override;

	sf::Vector2u _winsize;
	void getWin(sf::Vector2u winsize);

protected:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* currentAnimation;
};

