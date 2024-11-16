#include "Tank.h"

Tank::Tank(const std::string& name, int health, int attack, int defense, int speed, int magic, float damageMitigation)
    : Character(name, health, attack, defense, speed, magic), damageMitigation(damageMitigation) {}

float Tank::getDamageMitigation() const { return damageMitigation; }
void Tank::setDamageMitigation(float mitigation) { damageMitigation = mitigation; }
