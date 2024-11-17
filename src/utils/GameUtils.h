// GameUtils.h
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <vector>
#include "../characters/Character.h"
#include "../factories/CharacterFactory.h"
#include "../constants/Ids.h"

void presentGame();
std::vector<Object*> createObjects();
Character* createPlayer();
Character* createNPC();

#endif
