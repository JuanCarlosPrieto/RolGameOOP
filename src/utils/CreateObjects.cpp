#include "GameUtils.h"
#include <algorithm>
#include <random>
#include <ctime>

std::vector<Object*> allObjects() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::pair<std::string,std::pair<int,int>>> objects = Ids::objectsAvailable;

    sort(objects.begin(), objects.end(), [](std::pair<std::string,std::pair<int,int>> x, std::pair<std::string,std::pair<int,int>> y) {
        return x.second.first < y.second.first;
    });

    std::vector<Object*> createdObjects;  

    for (int i = 0; i < objects.size(); ++i) {
        createdObjects.push_back(new Object(objects[i].first, objects[i].second.first, objects[i].second.second, 1));
    }

    return createdObjects;
}

std::vector<Object*> createObjects() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));    

    int countAttack = 0;
    int countDefense = 0;
    int countProtection = 0;
    int countWisdom = 0;

    std::vector<std::pair<std::string,std::pair<int,int>>> objects = Ids::objectsAvailable;

    sort(objects.begin(), objects.end(), [](std::pair<std::string,std::pair<int,int>> x, std::pair<std::string,std::pair<int,int>> y) {
        return x.second.first < y.second.first;
    });

    for (int i = 0; i < objects.size(); ++i) {
        int type = objects[i].second.first;
        if (type == Ids::ObjectTypes::ATTACK) countAttack++;
        else if (type == Ids::ObjectTypes::DEFENSE) countDefense++;
        else if (type == Ids::ObjectTypes::PROTECTION) countProtection++;
        else countWisdom++;
    }

    std::uniform_int_distribution<> attack(0, countAttack - 1);
    std::uniform_int_distribution<> defense(0, countDefense - 1);
    std::uniform_int_distribution<> protection(0, countProtection - 1);
    std::uniform_int_distribution<> wisdom(0, countWisdom - 1);

    std::vector<Object*> createdObjects;
    int idx = attack(gen);
    createdObjects.push_back(new Object(objects[idx].first, objects[idx].second.first, objects[idx].second.second, 1));

    idx = countAttack + defense(gen);
    createdObjects.push_back(new Object(objects[idx].first, objects[idx].second.first, objects[idx].second.second, 1));

    idx = countAttack + countDefense + protection(gen);
    createdObjects.push_back(new Object(objects[idx].first, objects[idx].second.first, objects[idx].second.second, 1));

    idx = countAttack + countDefense + countProtection + wisdom(gen);
    createdObjects.push_back(new Object(objects[idx].first, objects[idx].second.first, objects[idx].second.second, 1));

    return createdObjects;
}