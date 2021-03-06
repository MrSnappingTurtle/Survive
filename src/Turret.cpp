#include "Turret.h"

Turret::Turret(Player* pPlayer, const sf::Vector2f& position, std::list<Bullet>* pLBullets, ImageManager* pImageManager, SoundManager* pSoundManager)
	:pPlayer_(pPlayer), pLBullets_(pLBullets), pSoundManager_(pSoundManager)
{
	positionGlobal_ = position;
	pBaseTexture_ = &pImageManager->turretBaseTexture;
	pTurretTexture_ = &pImageManager->turretTexture;
	baseSprite_.setTexture(*pBaseTexture_);
	turretSprite_.setTexture(*pTurretTexture_);
	turretSprite_.setOrigin(8.5f, 7.5f);
	baseSprite_.setOrigin(14.5, 13.5f);
	turretSprite_.setPosition(position);
	baseSprite_.setPosition(position);
}
void Turret::update(const sf::Time& dT)
{
	if (dead_)
		safeToDelete_ = true;
	sf::Vector2f closestZomPos(1000.0f, 1000.0f);
	float closestZomDistance = 1000.0f;
	for (auto& position : vZomPositions_)
	{
		float distance = sqrt(pow(positionGlobal_.x - position.x, 2) + pow(positionGlobal_.y - position.y, 2));
		if (distance < closestZomDistance)
		{
			closestZomDistance = distance;
			closestZomPos = position;
		}
	}


	if (closestZomDistance <= 320.0f)
	{
		rotationGlobal_ = (float)atan2(closestZomPos.y - positionGlobal_.y, closestZomPos.x - positionGlobal_.x) * 180 / 3.14159265358f;
		turretSprite_.setRotation(rotationGlobal_);
		if (bullets_ > 0 && firerateClock_.getElapsedTime().asSeconds() > firerate_)
		{
			pSoundManager_->playSound("rifle", positionGlobal_, pPlayer_->getPositionGlobal());
			firerateClock_.restart();
			pLBullets_->push_back(Bullet(false, positionGlobal_, sf::Vector2f((float)cos(rotationGlobal_ * 3.14159265358f / 180) * 1500, (float)sin(rotationGlobal_ * 3.14159265358f / 180) * 1500), 10));
			pLBullets_->back().setFromTurret(true);
		}
	}
	if (health_ <= 0)
		dead_ = true;
}
void Turret::preUpdate(const std::vector<sf::Vector2f>& positions) { vZomPositions_ = positions; }
//Getters
int Turret::getHealth() const { return health_; }
bool Turret::isDead() const { return dead_; }
bool Turret::isSafeToDelete() const { return safeToDelete_; }
sf::Sprite Turret::getBaseSprite() const { return baseSprite_; }
sf::Sprite Turret::getTurretSprite() const { return turretSprite_; }
//Setters
void Turret::setHealth(const int health) { health_ = health; }

