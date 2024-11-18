#include "GameUtils.h"
#include <unordered_map>
#include <unordered_set>

std::vector<Attack*> allAttacks() {
    std::vector<Object*> objects = allObjects();
    std::unordered_map<std::string, Object*> mapObjects;
    for (int i = 0; i < objects.size(); ++i) {
        mapObjects.insert({objects[i]->getName(), objects[i]});
    }

    std::vector<Attack*> result;
    std::vector<std::pair<std::string,std::pair<int,std::vector<std::string>>>> all_attacks = Ids::attacks;
    for (int i = 0; i < all_attacks.size(); ++i) {
        std::vector<Object*> attacks_objects;
        for (int j = 0; j < all_attacks[i].second.second.size(); ++j) {
            attacks_objects.push_back(mapObjects[all_attacks[i].second.second[j]]);
        }
        result.push_back(new Attack(all_attacks[i].first, all_attacks[i].second.first, attacks_objects));
    }
    
    return result;
}

std::vector<Attack*> setAttacksBasedOnObjects(std::vector<Object*> objects) {
    std::vector<Attack*> result;
    std::vector<Attack*> all_attacks = allAttacks();

    for (int i = 0; i < all_attacks.size(); ++i)  {
        bool ok = 1;
        for (int j = 0; j < all_attacks[i]->getObjectsRequired().size(); ++j) {
            bool contains = 0;
            for (int k = 0; k < objects.size(); ++k) {
                if (*objects[k] == *(all_attacks[i]->getObjectsRequired()[j])) {
                    contains = 1;
                }
            }
            if (!contains) {
                ok = 0; 
                break;
            }
        }
        if (ok) {
            result.push_back(all_attacks[i]);
        }
    }

    return result;
}