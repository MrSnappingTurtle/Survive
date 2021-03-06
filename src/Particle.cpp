#include "Particle.h"
#include <iostream>
Particle::Particle(const sf::Vector2f& position,
	const sf::Vector2f& startingSize,
	const sf::Vector2f& endingSize,
	const float direction,
	const float speed,
	const float speedAcceleration,
	const float life,
	const sf::Color& startingColor,
	const sf::Color& endingColor)
	:startingSize_(startingSize),
	endingSize_(endingSize),
	direction_(direction),
	speed_(speed),
	speedAcceleration_(speedAcceleration),
	life_(life),
	startingColor_(startingColor),
	endingColor_(endingColor)
{
	positionGlobal_ = position;
	particle_.setSize(startingSize_);
	particle_.setRotation(direction);
	particle_.setFillColor(startingColor_);
	sizeDifference_ = endingSize_ - startingSize_;
	colorDifference_ = sf::Vector3f((float)(endingColor_.r - startingColor_.r), (float)(endingColor_.g - startingColor_.g), (float)(endingColor_.b - startingColor_.b));
	directionVector_ = sf::Vector2f(cos(direction * 3.14f / 180.0f), sin(direction * 3.14f / 180.0f));
}

void Particle::update(const sf::Time& dT)
{
	//Percentage of life
	float timePassed = lifeClock_.getElapsedTime().asSeconds();
	float timePercent = timePassed / life_;



	//Size
	particle_.setSize(startingSize_ + timePercent * sizeDifference_);

	//Color
	sf::Vector3f currentColor = colorDifference_ * timePercent;
	sf::Color newColor(startingColor_ + sf::Color((int)currentColor.x, (int)currentColor.y, (int)currentColor.z, 0));
	float newAlpha = 255.0f - (255.0f * timePercent);
	newColor.a = (int)newAlpha;

	//Checks if dead
	if (newAlpha <= 0)
		dead_ = true;
	particle_.setFillColor(newColor);

	//Speed
	if (speed_ > 0)
		speed_ += speedAcceleration_ * dT.asSeconds();

	if (speed_ < 0)
		speed_ = 0;

	//Velocity
	velocity_ = speed_ * directionVector_;

	positionGlobal_ += velocity_ * dT.asSeconds() - emitterOffset_;

	particle_.setOrigin(particle_.getLocalBounds().width / 2.0f, particle_.getLocalBounds().height / 2.0f);
	particle_.setPosition(positionGlobal_);
}

//Getters
bool Particle::isDead() const { return dead_; }
sf::RectangleShape Particle::getParticle() const { return particle_; }

//Setters
void Particle::setEmitterOffset(const sf::Vector2f& offset) { emitterOffset_ = offset; }
