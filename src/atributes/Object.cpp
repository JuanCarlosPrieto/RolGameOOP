#include "Object.h"
#include <iostream>

// Constructor
Object::Object() : level(1) {}

Object::Object(const std::string& name, int type, int upgrade, int level)
    : name(name), type(type), upgrade(upgrade), level(level) {}

// Getters and Setters
std::string Object::getName() const { return name; }
void Object::setName(const std::string& name) { this->name = name; }

int Object::getType() const { return type; }
void Object::setType(int type) { this->type = type; }

int Object::getUpgrade() const { return upgrade; }
void Object::setUpgrade(int upgrade) { this->upgrade = upgrade; }

int Object::getLevel() const { return level; }
void Object::setLevel(int level) { this->level = level; }

// Usable methods
void Object::use(int amount) {
    std::cout << "Using object " << name << " with amount: " << amount << std::endl;
}

void Object::use(int amount, int target) {
    std::cout << "Using object " << name << " with amount: " << amount << " on target: " << target << std::endl;
}

// Overload operator
Object Object::operator+(const Object& other) {
    if (other.getName() == this->name && this->type == other.getType()) {
        return Object();
    }
    return *this;
}

bool Object::operator==(const Object& other) {
    return this->name == other.getName();
}
