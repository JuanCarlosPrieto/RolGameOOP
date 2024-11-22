#include "GameUtils.h"
#include <algorithm>
#include <random>
#include <ctime>

Character* createNPC(int level) {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));

    std::uniform_int_distribution<> characterTypeGen(1, 4);
    std::uniform_int_distribution<> names(0, Ids::npcNames.size() - 1);

    int characterType = characterTypeGen(gen);
    if (characterType == Ids::CharacterTypes::REGENERATOR) {
        std::uniform_int_distribution<> attack(5 * level / 4, 8 * level / 4);
        std::uniform_int_distribution<> defense(level / 4, 3 * level / 4);
        std::uniform_int_distribution<> speed(level / 4, 5 * level / 4);
        std::uniform_int_distribution<> maxHealthRecovery(3 * level / 4, 7 * level / 4);
        std::uniform_real_distribution<> healthRecovery(0, 1);

        Regenerator* player = CharacterFactory::createRegenerator(Ids::npcNames[names(gen)], 100, attack(gen), defense(gen), speed(gen), level, healthRecovery(gen), maxHealthRecovery(gen));

        std::uniform_int_distribution<> number(0, 3);
        if (level >= 8) {
            player->setObjects(createObjects());
        }
        else if (level >= 5) {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            npcObjects.erase(npcObjects.begin() + num);
            player->setObjects(npcObjects);
        }
        else if (level >= 3) {
            std::vector<Object*> npcObjects = createObjects();
            int num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            num1 = number(gen);
            while (num1 >= 3) num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            player->setObjects(npcObjects);
        }
        else {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            std::vector<Object*> newObjects = {new Object(*npcObjects[num])};
            player->setObjects(newObjects);
        }

        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));
        return player;
    }
    if (characterType == Ids::CharacterTypes::ROGUE) {
        std::uniform_int_distribution<> attack(5 * level / 4, 10 * level / 4);
        std::uniform_int_distribution<> defense(2 * level / 4, 5 * level / 4);
        std::uniform_int_distribution<> speed(level / 4, 5 * level / 4);
        std::uniform_real_distribution<> stealingChance(0, 1);

        Rogue* player = CharacterFactory::createRogue(Ids::npcNames[names(gen)], 100, attack(gen), defense(gen), speed(gen), level, stealingChance(gen));

        std::uniform_int_distribution<> number(0, 3);
        if (level >= 8) {
            player->setObjects(createObjects());
        }
        else if (level >= 5) {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            npcObjects.erase(npcObjects.begin() + num);
            player->setObjects(npcObjects);
        }
        else if (level >= 3) {
            std::vector<Object*> npcObjects = createObjects();
            int num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            num1 = number(gen);
            while (num1 >= 3) num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            player->setObjects(npcObjects);
        }
        else {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            std::vector<Object*> newObjects = {new Object(*npcObjects[num])};
            player->setObjects(newObjects);
        }
        
        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));
        return player;
    }
    if (characterType == Ids::CharacterTypes::TANK) {
        std::uniform_int_distribution<> attack(5 * level / 4, 2 * level);
        std::uniform_int_distribution<> defense(2 * level / 4 , 5 * level / 4);
        std::uniform_int_distribution<> speed(level / 4, 5 * level / 4);
        std::uniform_real_distribution<> mitigation(0, 1);

        Tank* player = CharacterFactory::createTank(Ids::npcNames[names(gen)], 100, attack(gen), defense(gen), speed(gen), level, mitigation(gen));

        std::uniform_int_distribution<> number(0, 3);
        if (level >= 8) {
            player->setObjects(createObjects());
        }
        else if (level >= 5) {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            npcObjects.erase(npcObjects.begin() + num);
            player->setObjects(npcObjects);
        }
        else if (level >= 3) {
            std::vector<Object*> npcObjects = createObjects();
            int num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            num1 = number(gen);
            while (num1 >= 3) num1 = number(gen);
            npcObjects.erase(npcObjects.begin() + num1);
            player->setObjects(npcObjects);
        }
        else {
            std::vector<Object*> npcObjects = createObjects();
            int num = number(gen);
            std::vector<Object*> newObjects = {new Object(*npcObjects[num])};
            player->setObjects(newObjects);
        }

        player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));
        return player;
    }
    std::uniform_int_distribution<> attack(2 * level, 3* level);
    std::uniform_int_distribution<> defense(2 * level / 4, 5 * level / 4);
    std::uniform_int_distribution<> speed(level / 4, 5 * level / 4);
    std::uniform_real_distribution<> hitChance(0, 1);

    Warrior* player = CharacterFactory::createWarrior(Ids::npcNames[names(gen)], 100, attack(gen), defense(gen), speed(gen), level, hitChance(gen));

    std::uniform_int_distribution<> number(0, 3);
    if (level >= 8) {
        player->setObjects(createObjects());
    }
    else if (level >= 5) {
        std::vector<Object*> npcObjects = createObjects();
        int num = number(gen);
        npcObjects.erase(npcObjects.begin() + num);
        player->setObjects(npcObjects);
    }
    else if (level >= 3) {
        std::vector<Object*> npcObjects = createObjects();
        int num1 = number(gen);
        npcObjects.erase(npcObjects.begin() + num1);
        num1 = number(gen);
        while (num1 >= 3) num1 = number(gen);
        npcObjects.erase(npcObjects.begin() + num1);
        player->setObjects(npcObjects);
    }
    else {
        std::vector<Object*> npcObjects = createObjects();
        int num = number(gen);
        std::vector<Object*> newObjects = {new Object(*npcObjects[num])};
        player->setObjects(newObjects);
    }

    player->setAttacks(setAttacksBasedOnObjects(player->getObjects()));   
    return player;
}