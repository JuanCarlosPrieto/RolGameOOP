// GameUtils.h
#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "../characters/Character.h"
#include "../factories/CharacterFactory.h"
#include "../constants/Ids.h"
#include <string>

void initializeGame();
void presentGame();
Character* createPlayer();

#endif
