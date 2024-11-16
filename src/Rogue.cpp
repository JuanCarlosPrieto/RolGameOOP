#include "Rogue.h"

Rogue::Rogue(const std::string& name, int health, int attack, int defense, int speed, int magic, float stealingChance)
    : Character(name, health, attack, defense, speed, magic), stealingChance(stealingChance) {}

float Rogue::getStealingChance() const { return stealingChance; }
void Rogue::setStealingChance(float chance) { stealingChance = chance; }
