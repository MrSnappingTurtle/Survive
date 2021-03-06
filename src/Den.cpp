#include "Den.h"

Den::Den(sf::Texture* texture)
{
    denTexture_ = texture;
    denSprite_.setTexture(*denTexture_);
    denSprite_.setOrigin(48.0f, 48.0f);
}
void Den::update(const sf::Time&)
{
    denSprite_.setPosition(positionGlobal_);
    if(spawnClock_.getElapsedTime().asMilliseconds() > spawnEvery_)
    {
        spawnClock_.restart();
        readyToSpawn_ = true;
    }
    else
        readyToSpawn_ = false;
    
    if(spawnSpeedClock_.getElapsedTime().asMilliseconds() > decreaseSpawnClockEvery_ && spawnEvery_ > 1000)
    {
        spawnSpeedClock_.restart();
        spawnEvery_ -= decreaseSpawnBy_;
    }
}

//Setters

//Getters
bool Den::isReadyToSpawn() const {return readyToSpawn_;}
sf::Sprite Den::getSprite() const {return denSprite_;}