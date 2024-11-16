#include "Attack.h"

Attack::Attack(const std::string& name, int damage) : name(name), damage(damage) {}

std::string Attack::getName() const { return name; }
void Attack::setName(const std::string& name) { this->name = name; }

int Attack::getDamage() const { return damage; }
void Attack::setDamage(int damage) { this->damage = damage; }
