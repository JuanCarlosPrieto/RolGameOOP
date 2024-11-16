#include "Regenerator.h"

Regenerator::Regenerator(const std::string& name, int health, int attack, int defense, int speed, int magic, float healthRecovery, int maxHealthRecovery)
    : Character(name, health, attack, defense, speed, magic), healthRecovery(healthRecovery), maxHealthRecovery(maxHealthRecovery) {}

float Regenerator::getHealthRecovery() const { return healthRecovery; }
void Regenerator::setHealthRecovery(float recovery) { healthRecovery = recovery; }

int Regenerator::getMaxHealthRecovery() const { return maxHealthRecovery; }
void Regenerator::setMaxHealthRecovery(int maxRecovery) { maxHealthRecovery = maxRecovery; }
