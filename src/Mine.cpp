#include "Mine.h"
#include <iostream>
Mine::Mine(sf::Texture* pTexture)
	:pTexture_(pTexture)
{
	mineSprite_.setTexture(*pTexture_);
}

void Mine::update(const sf::Time& dT)
{
	if (exploded_)
	{
		emitter_.update(dT);
	
		if (emitter_.isDead())
			dead_ = true;
		
	}

	mineSprite_.setPosition(positionGlobal_);
	mineSprite_.setRotation(rotationGlobal_);
}

//Getters
int Mine::getDamage() const { return damage_; }
int Mine::getRadius() const { return radius_; }
sf::Sprite Mine::getMine() const { return mineSprite_; }
bool Mine::exploded() const { return exploded_; }
Emitter Mine::getEmitter() const { return emitter_; }
bool Mine::isDead() const { return dead_; }
//Helpers
void Mine::explode()
{
	if (!exploded_)
	{
		emitter_ = Emitter(true,
			positionGlobal_,
			true,
			300,
			3000,
			sf::Vector2f(5.0f, 5.0f),
			sf::Vector2f(50.0f, 50.0f),
			0.0f,
			360.0f,
			0.0f,
			850.0f,
			-3000.0f,
			0.75f,
			1.25f,
			sf::Color(255, 225, 50, 255),
			sf::Color(250, 250, 250, 255));

		exploded_ = true;
		mineSprite_.setColor(sf::Color::Transparent);
	}
}

