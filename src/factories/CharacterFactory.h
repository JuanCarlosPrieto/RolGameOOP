// CharacterFactory.h
#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "../characters/Tank.h"
#include "../characters/Regenerator.h"
#include "../characters/Rogue.h"
#include "../characters/Warrior.h"

class CharacterFactory {
public:
    static Tank* createTank(std::string name, int health, int attack, int defense, int speed, int magic, float damageMitigation);
    static Regenerator* createRegenerator(std::string name, int health, int attack, int defense, int speed, int magic, float healthRecovery, int maxHealthRecovery);
    static Rogue* createRogue(std::string name, int health, int attack, int defense, int speed, int magic, float stealingChance);
    static Warrior* createWarrior(std::string name, int health, int attack, int defense, int speed, int magic, float criticalHitChance);
};

#endif
