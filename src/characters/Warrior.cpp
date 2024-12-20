#include <iostream>
#include "Warrior.h"

Warrior::Warrior(const std::string& name, int health, int attack, int defense, int speed, int magic, float hitChance)
    : Character(name, health, attack, defense, speed, magic), criticalHitChance(hitChance) {}

float Warrior::getCriticalHitChance() const { return criticalHitChance; }
void Warrior::setCriticalHitChance(float hitChance) { criticalHitChance = hitChance; }

Warrior& Warrior::operator+(const Character& other) {
    this->health = 100;
    this->magic += std::min(other.getMagic()/10, 1) + 1;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Warrior& character) {
    os<<"Nombre: "<<character.getName()<<std::endl;
    os<<"Salud: "<<character.getHealth()<<std::endl;
    os<<"Ataque: "<<character.getAttack()<<std::endl;
    os<<"Defensa: "<<character.getDefense()<<std::endl;
    os<<"Velocidad: "<<character.getSpeed()<<std::endl;
    os<<"Magia: "<<character.getMagic()<<std::endl;
    os<<"Probabilidad de ataque critico: "<<character.getCriticalHitChance()<<std::endl;
    if (character.getObjects().size() > 0) {
        os<<"Objetos recolectados: [";
        std::vector<Object*> objects = character.getObjects(); 
        for (int i = 0; i < objects.size(); ++i) {
            os<<objects[i]->getName()<<", ";
        }
        os<<"]"<<std::endl;
    }
    if (character.getAttacks().size() > 0) {
        os<<"Ataques aprendidos: [";
        std::vector<Attack*> attacks = character.getAttacks();
        for (int i = 0; i < attacks.size(); ++i) {
            os<<attacks[i]->getName()<<", ";
        }
        os<<"]"<<std::endl;
    }
    return os;
}