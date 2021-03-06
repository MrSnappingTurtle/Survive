
#ifndef GUIMANAGER_H
#define	GUIMANAGER_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ImageManager.h"
#include "SoundManager.h"
class GUIManager
{
 public:
  GUIManager(SoundManager*, ImageManager*, sf::RenderWindow*, Player*, int*, int*);
  void update(const sf::Time&);
  void reset();
    
  //Getters
  sf::RectangleShape getHealthOutOf() const;
  sf::RectangleShape getHealthCurrent() const;
  sf::RectangleShape getSprintOutOf() const;
  sf::RectangleShape getSprintCurrent() const;
  sf::Text getCurrentAmmo() const;
  sf::Text getTotalAmmo() const;
  sf::RectangleShape getReloadOutOf() const;
  sf::RectangleShape getReloadCurrent() const;
  sf::Text getWaveText() const;
  sf::Text getZombiesText() const;
  sf::RectangleShape getWaveBackground() const;
  sf::RectangleShape getBuyMenuBackground() const;
  sf::RectangleShape getExitButton() const;
  sf::RectangleShape getSelectionRect()  const;
  sf::Text getStoreText() const;
  sf::Text getPistolText() const;
  sf::Text getMagnumText() const;
  sf::Text getShotgunText() const;
  sf::Text getRifleText() const;
  sf::Text getRocketText() const;
  sf::Text getBarricadeText() const;
  sf::Text getTurretText() const; 
  sf::Text getMineText() const;
  sf::Text getBuyMagnumText() const;
  sf::Text getBuyShotgunText() const;
  sf::Text getBuyRifleText() const;
  sf::Text getBuyRocketText() const;
  sf::Text getBuyBarricadeText() const;
  sf::Text getBuyTurretText() const;
  sf::Text getBuyMineText() const;
  sf::Text getPointsText() const;
  sf::Text getBuyPistolAmmoText() const;
  sf::Text getBuyMagnumAmmoText() const;
  sf::Text getBuyShotgunAmmoText() const;
  sf::Text getBuyRifleAmmoText() const;
  sf::Text getBuyRocketAmmoText() const;
  sf::Sprite getPistolSprite() const;
  sf::Sprite getMagnumSprite() const;
  sf::Sprite getShotgunSprite() const;
  sf::Sprite getRifleSprite() const;
  sf::Sprite getRocketSprite() const;
  sf::Sprite getBarricadeSprite() const;
  sf::Sprite getTurretSprite() const;
  sf::Sprite getMineSprite() const;
  bool isOpen() const;
    
 private:
  //Allows only clicks to buy
  bool clickDown_ = false;
    
  ImageManager* pImageManager_;
  //Helpers for text
  void setUpText(sf::Text&, const std::string&);
  void showInStore(sf::Text&, const float, const float, const float);
  void showInStore(sf::Sprite&, const float, const float);

  bool hover(const sf::Text&);
  sf::RenderWindow* pWindow_;
  SoundManager* pSoundManager_ = nullptr;
  Player* pPlayer_;
  sf::Font font_;
  int* pWave_;
  int* pZombiesAlive_;
    
  //Store pics
  sf::Sprite pistolSprite_;
  sf::Sprite magnumSprite_;
  sf::Sprite shotgunSprite_;
  sf::Sprite rifleSprite_;
  sf::Sprite rocketSprite_;
  sf::Sprite barricadeSprite_;
  sf::Sprite turretSprite_;
  sf::Sprite mineSprite_;

  //Wave info
  sf::Text waveText_;
  sf::Text zombiesText_;
  sf::RectangleShape waveBackground_;
  float waveTextSize_ = 0.05f;
  float zombiesTextSize_ = 0.05f;
  float pointsTextSize_ = 0.05f;
  sf::Vector2f waveBackgroundSize_ = sf::Vector2f(0.2f, 0.21f);
  sf::Vector2f waveTextOffset_ = sf::Vector2f(0.05f, 0.01f);
  sf::Vector2f zombiesTextOffset_ = sf::Vector2f(0.05f, 0.06f);

  //Points
  sf::Text pointsText_;
  sf::Vector2f pointsTextOffset_ = sf::Vector2f(0.05f, 0.11f);
    
  //Health
  sf::RectangleShape healthOutOf_;
  sf::RectangleShape healthCurrent_;
  sf::Vector2f healthOffset_ = sf::Vector2f(0.01f, 0.01f); //In percent of window size
  sf::Vector2f healthSize_ = sf::Vector2f(0.075f, 0.01f); //In percent of window size
    
  //Sprint
  sf::RectangleShape sprintOutOf_;
  sf::RectangleShape sprintCurrent_;
  sf::Vector2f sprintOffset_ = sf::Vector2f(0.5, 0.01f);

  //Weapon
  sf::Text ammo_;
  sf::Vector2f ammoOffset_ = sf::Vector2f(0.015f, 0.015f);
  float ammoSize_ = 0.035f; //In percent 
    
  //Reload
  sf::RectangleShape reloadOutOf_;
  sf::RectangleShape reloadCurrent_;
  sf::Vector2f reloadOffset_ = sf::Vector2f(0.01f, 0.01f);
  sf::Vector2f reloadSize_ = sf::Vector2f(0.075f, 0.01f);
    
  //----------------Buy menu--------------
  //Basic
  bool storeOpen_ = false;
  bool toggled_ = false;
  float storeOpenTime_ = 0.1f;
  float storeItemsOpenTime_ = 0.1f;
  sf::RectangleShape buyMenuBackground_;
  sf::RectangleShape exitButton_;
  sf::RectangleShape selectionRect_;
  sf::Vector2f storeSize_ = sf::Vector2f(0.9f, 0.6f);
    
  bool magnumBought_ = false;
  bool shotgunBought_ = false;
  bool rifleBought_ = false;
  bool rocketBought_ = false;
    
  //Gun/Item texts
  sf::Text storeText_;
  sf::Text pistolText_;
  sf::Text magnumText_;
  sf::Text shotgunText_;
  sf::Text rifleText_;
  sf::Text rocketText_;
  sf::Text barricadeText_;
  sf::Text turretText_;
  sf::Text mineText_;
  float itemTextSize_ = 0.05f;
  float titleTextSize_ = 0.1f;
  //Gun/Item prices
  int priceMagnum_ = 1750;
  int priceShotgun_ = 2550;
  int priceRifle_ = 4000;
  int priceRocket_ = 5500;
  int priceBarricade_ = 100;
  int priceTurret_ = 2250;
  int priceMine_ = 100;
  int priceAmmoPistol_ = 25;
  int priceAmmoMagnum_ = 75;
  int priceAmmoShotgun_ = 150;
  int priceAmmoRifle_ = 250;
  int priceAmmoRocket_ = 300;
  int pistolAmmoIncrease_ = 45;
  int magnumAmmoIncrease_ = 24;
  int shotgunAmmoIncrease_ = 10;
  int rifleAmmoIncrease_ = 90;
  int rocketAmmoIncrease_ = 5;
    
  //Buy button texts
  sf::Text buyMagnumText_;
  sf::Text buyShotgunText_;
  sf::Text buyRifleText_;
  sf::Text buyRocketText_;
  sf::Text buyBarricadeText_;
  sf::Text buyTurretText_;
  sf::Text buyMineText_;
  sf::Text buyPistolAmmoText_;
  sf::Text buyMagnumAmmoText_;
  sf::Text buyShotgunAmmoText_;
  sf::Text buyRifleAmmoText_;
  sf::Text buyRocketAmmoText_;
    
  //Clocks
  sf::Clock storeOpenClock_;
    
    
};

#endif	
