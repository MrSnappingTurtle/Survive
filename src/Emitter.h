#ifndef EMITTER_H
#define EMITTER_H
#include "GameObject.h"
#include <list>
#include "Particle.h"

class Emitter : public GameObject
{
 public:
  Emitter();
  Emitter(const bool, const sf::Vector2f&, const bool, const int, const int, const sf::Vector2f&, const sf::Vector2f&, const float, const float, const float, const float, const float, const float, const float, const sf::Color&, const sf::Color&);
  void update(const sf::Time&);

  //Getters
  std::list<Particle> getParticles() const;
  int getParticlesToSpawn() const;
  bool isDead() const;
  
  //Setters
  void setParticlesToEmit(const int);
 private:
  std::list<Particle> lParticles_;

  //Are the particle positions relative to the emitter
  bool relativeParticles_;
  sf::Vector2f lastPos_;

  //Is it ready to be deleted
  bool dead_ = false;
  
  //Does the emitter spawn particles until death
  bool hasSpawnLimit_;
  
  //The number of particles to spawn(if there is no limit)
  int particlesToSpawn_;

  //How many particles per second are spawned
  int particlesPerSecond_;

  //The sizes of the particles
  sf::Vector2f startingParticleSize_;
  sf::Vector2f endingParticleSize_;
  
  //At which direction in degrees the particle can come out from
  float minDirection_;
  float maxDirection_;
  
  //At which speed the particle can come out
  float minSpeed_;
  float maxSpeed_;

  //How fast the speed decays/accelerates
  float speedAcceleration_;

  //How long the particles live in seconds
  float minLife_;
  float maxLife_;
  
  //The starting and ending color
  sf::Color startingColor_;
  sf::Color endingColor_;

  //Clock used to determine when to spawn particles
  sf::Clock spawnClock_;
};

#endif
