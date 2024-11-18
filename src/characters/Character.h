#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "../atributes/Attack.h"
#include "../atributes/Object.h"
#include "../interfaces/Playable.h"

class Character {
protected:
    std::string name;
    int health;
    int attack;
    int defense;
    int speed;
    int magic;
    std::vector<Object*> objects;
    std::vector<Attack*> attacks;

public:
    Character(const std::string& name, int health, int attack, int defense, int speed, int magic);

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string& name);

    int getHealth() const;
    void setHealth(int health);

    int getAttack() const;
    void setAttack(int attack);

    int getDefense() const;
    void setDefense(int defense);

    int getSpeed() const;
    void setSpeed(int speed);

    int getMagic() const;
    void setMagic(int magic);

    std::vector<Object*> getObjects() const;
    void setObjects(const std::vector<Object*>& objects);

    std::vector<Attack*> getAttacks() const;
    void setAttacks(const std::vector<Attack*>& attacks);    

    // Overload operator
    virtual Character& operator+(const Character& other) = 0;    
    virtual ~Character() = default;
};

#endif
