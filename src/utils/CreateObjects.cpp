#include "GameUtils.h"
#include <algorithm>
#include <random>
#include <ctime>

std::vector<Object*> generateObjects() {
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));    

    int countAttack = 0;
    int countDefense = 0;
    int countProtection = 0;
    int countWisdom = 0;

    std::vector<std::tuple<std::string,int,int>> objects = Ids::objectsAvailable;

    sort(objects.begin(), objects.end(), [](std::tuple<std::string,int,int> x, std::tuple<std::string,int,int> y) {
        return std::get<1>(x) < std::get<1>(y);
    });

    for (int i = 0; i < objects.size(); ++i) {
        auto [name, type, upgrade] = objects[i];
        if (type == Ids::ObjectTypes::ATTACK) countAttack++;
        else if (type == Ids::ObjectTypes::DEFENSE) countDefense++;
        else if (type == Ids::ObjectTypes::PROTECTION) countProtection++;
        else countWisdom++;
    }

    std::uniform_int_distribution<> attack(0, countAttack - 1);
    std::uniform_int_distribution<> defense(0, countDefense - 1);
    std::uniform_int_distribution<> protection(0, countProtection - 1);
    std::uniform_int_distribution<> wisdom(0, countWisdom - 1);

    std::vector<Object*> generatedObjects;
    int idx = attack(gen);
    generatedObjects.push_back(new Object(std::get<0>(objects[idx]), std::get<1>(objects[idx]), std::get<2>(objects[idx]), 1));

    idx = countAttack + defense(gen);
    generatedObjects.push_back(new Object(std::get<0>(objects[idx]), std::get<1>(objects[idx]), std::get<2>(objects[idx]), 1));

    idx = countAttack + countDefense + protection(gen);
    generatedObjects.push_back(new Object(std::get<0>(objects[idx]), std::get<1>(objects[idx]), std::get<2>(objects[idx]), 1));

    idx = countAttack + countDefense + countProtection + wisdom(gen);
    generatedObjects.push_back(new Object(std::get<0>(objects[idx]), std::get<1>(objects[idx]), std::get<2>(objects[idx]), 1));

    return generatedObjects;
}