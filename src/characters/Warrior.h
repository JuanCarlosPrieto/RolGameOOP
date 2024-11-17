#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Tank : public Character {
private:
    float criticalHitChance;

public:
    Tank(const std::string& name, int health, int attack, int defense, int speed, int magic, float hitChance);

    float getCriticalHitChance() const;
    void setCriticalHitChance(float hitChance);
};

#endif