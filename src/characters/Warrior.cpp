#include "Warrior.h"

Warrior::Warrior(const std::string& name, int health, int attack, int defense, int speed, int magic, float hitChance)
    : Character(name, health, attack, defense, speed, magic), criticalHitChance(hitChance) {}

float Warrior::getCriticalHitChance() const { return damageMitigation; }
void Warrior::setCriticalHitChance(float hitChance) { criticalHitChance = hitChance; }