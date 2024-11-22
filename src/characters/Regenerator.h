#ifndef REGENERATOR_H
#define REGENERATOR_H

#include "Character.h"

class Regenerator : public Character {
private:
    float healthRecovery;
    int maxHealthRecovery;

public:
    Regenerator(const std::string& name, int health, int attack, int defense, int speed, int magic, float healthRecovery, int maxHealthRecovery);

    float getHealthRecovery() const;
    void setHealthRecovery(float recovery);

    int getMaxHealthRecovery() const;
    void setMaxHealthRecovery(int maxRecovery);

    Regenerator& operator+(const Character& other) override;
};

std::ostream& operator<<(std::ostream& os, const Regenerator& character);

#endif
