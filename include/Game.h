#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Equipment.h"

int playDungeon(Player& p, const Equipment& eq, int maxAttempts, bool verbose);

#endif //GAME_H