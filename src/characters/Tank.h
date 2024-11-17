#ifndef TANK_H
#define TANK_H

#include "Character.h"

class Tank : public Character {
private:
    float damageMitigation;

public:
    Tank(const std::string& name, int health, int attack, int defense, int speed, int magic, float damageMitigation);

    float getDamageMitigation() const;
    void setDamageMitigation(float mitigation);

    Tank& operator+(const Character& other) override;
};

std::ostream& operator<<(std::ostream& os, const Tank& character);

#endif
