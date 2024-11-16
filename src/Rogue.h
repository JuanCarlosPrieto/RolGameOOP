#ifndef ROGUE_H
#define ROGUE_H

#include "Character.h"

class Rogue : public Character {
private:
    float stealingChance;

public:
    Rogue(const std::string& name, int health, int attack, int defense, int speed, int magic, float stealingChance);

    float getStealingChance() const;
    void setStealingChance(float chance);
};

#endif