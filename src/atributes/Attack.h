#ifndef ATTACK_H
#define ATTACK_H

#include <vector>
#include <string>
#include "Object.h"

class Attack {
private:
    std::string name;
    int damage;
    std::vector<Object*> objectsRequired;

public:
    Attack(const std::string& name, int damage);
    Attack(const std::string& name, int damage, const std::vector<Object*>& objectsRequired);

    std::string getName() const;
    void setName(const std::string& name);

    int getDamage() const;
    void setDamage(int damage);

    std::vector<Object*> getObjectsRequired() const;
    void setObjectsRequired(std::vector<Object*> objects);
};

#endif
