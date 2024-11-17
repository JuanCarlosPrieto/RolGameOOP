#include "CharacterFactory.h"
#include <string>

Tank* CharacterFactory::createTank(std::string name, int health, int attack, int defense, int speed, int magic, float damageMitigation) {
    return new Tank(name, health, attack, defense, speed, magic, damageMitigation);
}

Regenerator* CharacterFactory::createRegenerator(std::string name, int health, int attack, int defense, int speed, int magic, float healthRecovery, int maxHealthRecovery) {
    return new Regenerator(name, health, attack, defense, speed, magic, healthRecovery, maxHealthRecovery);
}

Rogue* CharacterFactory::createRogue(std::string name, int health, int attack, int defense, int speed, int magic, float stealingChance) {
    return new Rogue(name, health, attack, defense, speed, magic, stealingChance);
}

Warrior* CharacterFactory::createWarrior(std::string name, int health, int attack, int defense, int speed, int magic, float criticalHitChance) {
    return new Warrior(name, health, attack, defense, speed, magic, criticalHitChance);
}