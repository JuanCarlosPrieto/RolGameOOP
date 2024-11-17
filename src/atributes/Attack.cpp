#include "Attack.h"

Attack::Attack(const std::string& name, int damage) : name(name), damage(damage) {}
Attack::Attack(const std::string& name, int damage, const std::vector<Object*>& objectsRequired) 
: name(name), damage(damage), objectsRequired(objectsRequired) {}

std::string Attack::getName() const { return name; }
void Attack::setName(const std::string& name) { this->name = name; }

int Attack::getDamage() const { return damage; }
void Attack::setDamage(int damage) { this->damage = damage; }

std::vector<Object*> Attack::getObjectsRequired() const { return objectsRequired; }
void Attack::setObjectsRequired(std::vector<Object*> objects) { this->objectsRequired = objects; }