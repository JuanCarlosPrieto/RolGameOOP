#include "Character.h"
#include <random>
#include <ctime>

// Constructor
Character::Character(const std::string& name, int health, int attack, int defense, int speed, int magic)
    : name(name), health(health), attack(attack), defense(defense), speed(speed), magic(magic) {}

// Getters and Setters
std::string Character::getName() const { return name; }
void Character::setName(const std::string& name) { this->name = name; }

int Character::getHealth() const { return health; }
void Character::setHealth(int health) { this->health = health; }

int Character::getAttack() const { return attack; }
void Character::setAttack(int attack) { this->attack = attack; }

int Character::getDefense() const { return defense; }
void Character::setDefense(int defense) { this->defense = defense; }

int Character::getSpeed() const { return speed; }
void Character::setSpeed(int speed) { this->speed = speed; }

int Character::getMagic() const { return magic; }
void Character::setMagic(int magic) { this->magic = magic; }

std::vector<Object*> Character::getObjects() const { return objects; }
void Character::setObjects(const std::vector<Object*>& objects) { this->objects = objects; }

std::vector<Attack*> Character::getAttacks() const { return attacks; }
void Character::setAttacks(const std::vector<Attack*>& attacks) { this->attacks = attacks; }

int Character::attack_func() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_real_distribution<> factor(1, this->objects.size() + 2);

    return this->attack * (this->magic / 10 + 1)* factor(gen) * 5;
}

int Character::defend_func(int damage_mit) {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_real_distribution<> factor(0, damage_mit);

    return this->attack * (this->magic / 10 + 1) * factor(gen);
}