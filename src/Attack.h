#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class Attack {
private:
    std::string name;
    int damage;

public:
    Attack(const std::string& name, int damage);

    std::string getName() const;
    void setName(const std::string& name);

    int getDamage() const;
    void setDamage(int damage);
};

#endif
