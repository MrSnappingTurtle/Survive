#include "Emitter.h"
#include <iostream> 
Emitter::Emitter(){}
Emitter::Emitter(const bool relativeParticles,
		 const sf::Vector2f& position,
	     const bool hasSpawnLimit,
		 const int particlesToSpawn,
		 const int particlesPerSecond,
		 const sf::Vector2f& startingParticleSize,
		 const sf::Vector2f& endingParticleSize,
		 const float minDirection,
		 const float maxDirection,
		 const float minSpeed,
		 const float maxSpeed,
		 const float speedAcceleration,
		 const float minLife,
		 const float maxLife,
		 const sf::Color& startingColor,
		 const sf::Color& endingColor)
    :relativeParticles_(relativeParticles),
     hasSpawnLimit_(hasSpawnLimit),
     particlesToSpawn_(particlesToSpawn),
     particlesPerSecond_(particlesPerSecond),
     startingParticleSize_(startingParticleSize),
     endingParticleSize_(endingParticleSize),
     minDirection_(minDirection),
     maxDirection_(maxDirection),
     minSpeed_(minSpeed),
     maxSpeed_(maxSpeed),
     speedAcceleration_(speedAcceleration),
     minLife_(minLife),
     maxLife_(maxLife),
     startingColor_(startingColor),
     endingColor_(endingColor)
{
	positionGlobal_ = position;
}
    
void Emitter::update(const sf::Time& dT)
{
	if (particlesToSpawn_ <= 0 && lParticles_.empty())
		dead_ = true;

	sf::Vector2f offset = lastPos_ - positionGlobal_;
	lastPos_ = positionGlobal_;

	if(spawnClock_.getElapsedTime().asSeconds() >= 1.0f / particlesPerSecond_ && particlesToSpawn_ > 0)
	{
	    int numToSpawn = (int)(spawnClock_.getElapsedTime().asSeconds() / (1.0f / particlesPerSecond_));
	    particlesToSpawn_ -= numToSpawn;
	    spawnClock_.restart();

	    for (int i = 0; i < numToSpawn; ++i)
	    {
			float direction = minDirection_ + (float)fmod(std::rand(), (maxDirection_ - minDirection_));
			float speed = minSpeed_ + (float)fmod(std::rand(), (maxSpeed_ - minSpeed_));
			float life = minLife_ + (float)fmod(std::rand(), (maxLife_ - minLife_));
		lParticles_.push_back(Particle(positionGlobal_,
					       startingParticleSize_,
					       endingParticleSize_,
					       direction,
					       speed,
					       speedAcceleration_,
					       life,
					       startingColor_,
					       endingColor_));

	    }
	}		
    for(auto iParticle = lParticles_.begin(); iParticle != lParticles_.end();)
    {
		if(relativeParticles_)
			iParticle->setEmitterOffset(offset);

		//Updates the particle
		iParticle->update(dT);

		//Checks if it is dead, erases if so, iterates otherwise
		if(iParticle->isDead())
			iParticle = lParticles_.erase(iParticle);
		else
			++iParticle;
    }
}

std::list<Particle> Emitter::getParticles() const { return lParticles_; }
int Emitter::getParticlesToSpawn() const { return particlesToSpawn_; }
bool Emitter::isDead() const { return dead_; }

//Setters
void Emitter::setParticlesToEmit(const int particles) { particlesToSpawn_ = particles; }