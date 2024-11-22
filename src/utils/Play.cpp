#include "GameUtils.h"
#include <iostream>

void play(Character* player1, Character* player2) {
    bool turn = 0;
    while (player1->getHealth() > 0 && player2->getHealth() > 0) {
        if (!turn) {
            int option;
            std::cout<<"Mi vida: "<<player1->getHealth()<<"     "<<"Vida oponente: "<<player2->getHealth()<<std::endl;
            std::cout<<"Escoge un ataque: "<<std::endl;
            for (int i = 0; i < player1->getAttacks().size(); ++i) {
                std::cout<<i+1<<(*(player1->getAttacks()[i])).getName()<<std::endl;
            }
            std::cin>>option;
            int dam = player1->attack_func();
            int def = player2->defend_func(player2->getDefense() / (player2->getDefense() + 10));
            player2->setHealth(player2->getHealth() - std::max(0, dam - def));
        }
        else {
            int dam = player2->attack_func();
            int def = player1->defend_func(player2->getDefense() / (player2->getDefense() + 10));
            player1->setHealth(player1->getHealth() - std::max(0, dam - def));
        }
    }
    if (player1->getHealth() > 0) {
        *player1 = *player1 + *player2;
        std::cout<<"Felicitaciones ganaste!!!!"<<std::endl;
    }
    else {
        player1->setHealth(100);
        std::cout<<"Lo sentimos, perdiste!"<<std::endl;
    }
}

void play(Character* player1, Character* player2, int& level) {
    bool turn = 0;
    while (player1->getHealth() > 0 && player2->getHealth() > 0) {
        if (!turn) {
            int option;
            std::cout<<"Mi vida: "<<player1->getHealth()<<"     "<<"Vida oponente:  "<<player2->getHealth()<<std::endl;
            std::cout<<"Escoge un ataque: "<<std::endl;
            for (int i = 0; i < player1->getAttacks().size(); ++i) {
                std::cout<<i+1<<(*(player1->getAttacks()[i])).getName()<<std::endl;
            }
            std::cin>>option;
            int dam = player1->attack_func();
            int def = player2->defend_func(player2->getDefense() / (player2->getDefense() + 10));
            player2->setHealth(player2->getHealth() - std::max(0, dam - def));
        }
        else {
            int dam = player2->attack_func();
            int def = player1->defend_func(player1->getDefense() / (player1->getDefense() + 10));
            player1->setHealth(player1->getHealth() - std::max(0, dam - def));
        }
        turn = !turn;
    }
    if (player1->getHealth() > 0) {
        *player1 = *player1 + *player2;
        level += 1;
        std::cout<<"Felicitaciones ganaste!!!!"<<std::endl;
    }
    else {
        player1->setHealth(100);
        std::cout<<"Lo sentimos, perdiste!"<<std::endl;
    }
}