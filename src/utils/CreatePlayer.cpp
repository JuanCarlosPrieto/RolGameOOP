#include "GameUtils.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

Character* createPlayer() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));    

    std::string username;
    int characterType;

    std::cout<<"Bienvenido al juego, para empezar, dinos tu nombre: "<<std::endl;
    std::getline(std::cin, username);
    while (count(username.begin(), username.end(), ' ') != 0) {
        system("cls");
        std::cout<<"Please select a name without spaces: "<<std::endl;
        std::cout<<"Bienvenido al juego, para empezar, dinos tu nombre: "<<std::endl;
        std::getline(std::cin, username);
    }


    std::cout<<"Ahora escoge el tipo de personaje que quieres ser: "<<std::endl;
    std::cout<<"Reactivador: "<<Ids::CharacterTypes::REGENERATOR<<std::endl;
    std::cout<<"Pillo: "<<Ids::CharacterTypes::ROGUE<<std::endl;
    std::cout<<"Tanque: "<<Ids::CharacterTypes::TANK<<std::endl;
    std::cout<<"Guerrero: "<<Ids::CharacterTypes::WARRIOR<<std::endl;
    std::cout<<">";

    std::cin>>characterType;

    while (characterType < 1 || characterType > 4) {
        system("cls");
        std::cout<<"Escoge un tipo de personaje valido"<<std::endl;
        std::cout<<"Ahora escoge el tipo de personaje que quieres ser: "<<std::endl;
        std::cout<<"Reactivador: "<<Ids::CharacterTypes::REGENERATOR<<std::endl;
        std::cout<<"Pillo: "<<Ids::CharacterTypes::ROGUE<<std::endl;
        std::cout<<"Tanque: "<<Ids::CharacterTypes::TANK<<std::endl;
        std::cout<<"Guerrero: "<<Ids::CharacterTypes::WARRIOR<<std::endl;
        std::cout<<">";
    }

    if (characterType == Ids::CharacterTypes::REGENERATOR) {
        std::uniform_int_distribution<> attack(5, 8);
        std::uniform_int_distribution<> defense(1, 3);
        std::uniform_int_distribution<> speed(1, 5);
        std::uniform_int_distribution<> maxHealthRecovery(3, 7);
        std::uniform_real_distribution<> healthRecovery(0, 1);

        Regenerator* player = CharacterFactory::createRegenerator(username, 100, attack(gen), defense(gen), speed(gen), 0, healthRecovery(gen), maxHealthRecovery(gen));

        std::cout<<"Estas son las estadisticas de tu personaje"<<std::endl;
        std::cout<< *player <<std::endl;

        std::vector<Object*> available = createObjects();
        std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
        for (int i = 0; i < available.size(); ++i) {
            std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
        }
        std::cout<<">";

        int choose;
        std::cin>>choose;

        while (choose < 1 || choose > 4) {
            std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
            for (int i = 0; i < available.size(); ++i) {
                std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
            }
            std::cout<<">";
            std::cin>>choose;
        }

        std::vector<Object*> playerObjects = {new Object(*available[choose - 1])};
        player->setObjects(playerObjects);
        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));

        return player;
    }
    if (characterType == Ids::CharacterTypes::ROGUE) {
        std::uniform_int_distribution<> attack(5, 10);
        std::uniform_int_distribution<> defense(2, 5);
        std::uniform_int_distribution<> speed(1, 5);
        std::uniform_real_distribution<> stealingChance(0, 1);

        Rogue* player = CharacterFactory::createRogue(username, 100, attack(gen), defense(gen), speed(gen), 0, stealingChance(gen));

        std::cout<<"Estas son las estadisticas de tu personaje"<<std::endl;
        std::cout<< *player <<std::endl;

        std::vector<Object*> available = createObjects();
        std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
        for (int i = 0; i < available.size(); ++i) {
            std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
        }
        std::cout<<">";

        int choose;
        std::cin>>choose;

        while (choose < 1 || choose > 4) {
            std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
            for (int i = 0; i < available.size(); ++i) {
                std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
            }
            std::cout<<">";
            std::cin>>choose;
        }

        std::vector<Object*> playerObjects = {new Object(*available[choose - 1])};
        player->setObjects(playerObjects);
        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));

        return player;
    }
    if (characterType == Ids::CharacterTypes::TANK) {
        std::uniform_int_distribution<> attack(5, 8);
        std::uniform_int_distribution<> defense(2, 5);
        std::uniform_int_distribution<> speed(1, 5);
        std::uniform_real_distribution<> mitigation(0, 1);

        Tank* player = CharacterFactory::createTank(username, 100, attack(gen), defense(gen), speed(gen), 0, mitigation(gen));

        std::cout<<"Estas son las estadisticas de tu personaje"<<std::endl;
        std::cout<< *player <<std::endl;

        std::vector<Object*> available = createObjects();
        std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
        for (int i = 0; i < available.size(); ++i) {
            std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
        }
        std::cout<<">";

        int choose;
        std::cin>>choose;

        while (choose < 1 || choose > 4) {
            std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
            for (int i = 0; i < available.size(); ++i) {
                std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
            }
            std::cout<<">";
            std::cin>>choose;
        }

        std::vector<Object*> playerObjects = {new Object(*available[choose - 1])};
        player->setObjects(playerObjects);
        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));

        return player;
    }

    std::uniform_int_distribution<> attack(8, 12);
    std::uniform_int_distribution<> defense(2, 5);
    std::uniform_int_distribution<> speed(1, 5);
    std::uniform_real_distribution<> hitChance(0, 1);

    Warrior* player = CharacterFactory::createWarrior(username, 100, attack(gen), defense(gen), speed(gen), 0, hitChance(gen));

    std::cout<<"Estas son las estadisticas de tu personaje"<<std::endl;
    std::cout<< *player <<std::endl;

    std::vector<Object*> available = createObjects();
    std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
    for (int i = 0; i < available.size(); ++i) {
        std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
    }
    std::cout<<">";

    int choose;
    std::cin>>choose;

    while (choose < 1 || choose > 4) {
        std::cout<<"Ahora tienes que escoger uno de los siguientes objetos que te ayudaran en el desafio: "<<std::endl;
        for (int i = 0; i < available.size(); ++i) {
            std::cout<<i + 1<<". "<<available[i]->getName()<<std::endl;
        }
        std::cout<<">";
        std::cin>>choose;
    }

    std::vector<Object*> playerObjects = {new Object(*available[choose - 1])};
    player->setObjects(playerObjects);
    player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));

    return player;
}