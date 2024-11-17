#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
private:
    float criticalHitChance;

public:
    Warrior(const std::string& name, int health, int attack, int defense, int speed, int magic, float hitChance);

    float getCriticalHitChance() const;
    void setCriticalHitChance(float hitChance);

    Warrior& operator+(const Character& other) override;
};

std::ostream& operator<<(std::ostream& os, const Warrior& character);

#endif