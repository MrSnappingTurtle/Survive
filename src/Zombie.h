#ifndef ZOMBIE_H
#define	ZOMBIE_H
#include <memory>
#include <mutex>
#include <stack>
#include "Humanoid.h"
#include "Emitter.h"
#include "Player.h"
#include "Tile.h"
#include "Turret.h"
#include "Node.h"
#include "Barricade.h"
#include "SoundManager.h"

class Zombie : public Humanoid
{
 public:
  Zombie(Player*, SoundManager*, const std::string&, sf::Texture*, sf::Texture*, const int, const int);
  void update(const sf::Time&);

  //Fills the sPNodes_ stack with node ptr
  void findPath(std::vector< std::vector<Tile> >*);

  //Getters
  bool needsPath();
  bool countedDead();
  bool bled();
  bool droppedHealth() const;
  bool isStill() const;
  bool isDead() const;
  bool isDeletable() const;
  bool isReadyToRepath() const;
  std::string getType() const;
  std::vector<Emitter> getEmitters() const;
  sf::Sprite getCorpseSprite() const;
  std::stack<Node> getNodes() const;
  Emitter getExplosionEmitter() const;
  bool damagedOthers() const;
  float getShake();
  //Setters
  void setTurretPtr(Turret*);
  void setBarricadePtr(Barricade*);
  void setNeedsPath(bool);
  void setExploded(const bool);
  void setDamagedOthers(const bool);
  void setBulletListPtr(std::list<Bullet>*);
  void setDroppedHealth(const bool);
    
  //Operator overloading
  bool operator== (const Zombie&) const;
  /*Zombie& operator= (Zombie&& other);
    Zombie& operator= (const Zombie& other);*/
 private:

  std::string type_;
  //A pointer to the player used to get information such as position
  Player* pPlayer_;
  
  //A stack of nodes that leads to the target
  std::stack<Node> sPNodes_;

  //Needs path if stuck
  bool needsPath_ = false;
    
  //A pointer to the nearest attackable item
  Turret* pTurret_ = nullptr;
  Barricade* pBarricade_ = nullptr;

  //The position of the target
  sf::Vector2i targetPosition_;
    
  //A normalized vector that points towards the player, from the zombie
  sf::Vector2f targetVector_;

  //Used to find out when pathing should run
  sf::Vector2i lastTargetPosition_;
  bool readyToRepath_ = true;
    
  Emitter explosionEmitter_; 

  //The corpse texture
  sf::Texture* pCorpseTexture_;
  sf::Sprite corpseSprite_;
    
  bool droppedHealth_ = false;
  sf::Clock armClock_;
  sf::Clock attackClock_;
  bool attacking_ = false;
  bool hit_ = false;
  bool dead_ = false;
  bool still_ = false;
  bool delete_ = false;
  bool countedDead_ = false;
  bool bleed_ = false; //Used for bleeding when sliding
  bool fading_ = false;
  float armLeftVerticalOffset_;
  float armRightVerticalOffset_;
  float armLeftHorizontalOffset_;
  float armRightHorizontalOffset_;
  float corpseSpeed_ = 0;
  float fadeAfter_ = 10.0f;
  float fadeFor_ = 5.0f;

  //Shake from exploding zombie
  float shake_ = 0.0f;

  bool exploded_ = false;
  bool explosionDamagedOthers_ = false;

  //Type: shooting
  sf::Clock firerateClock_;

  //Type: ranged
  //Pointer to the bullets list(for ranged zombies)
  std::list<Bullet>* pLBullets_ = nullptr;
  
  //Sound manager
  SoundManager* pSoundManager_;

  float moanTime_ = 5.0f;
  //Clocks
  sf::Clock fadeAfterClock_;
  sf::Clock fadeForClock_;
  sf::Clock bleedClock_;
  sf::Clock pathClock_;
  sf::Clock moanClock_;
};

//Functor used to compare Node pointers
struct compNode
{
  bool operator() (Node*, Node*);
};
#endif	

