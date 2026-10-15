#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Equipment.h"

int playDungeon(Player& p, const Equipment& eq, int maxAttempts, bool verbose);

// Interactive game (console menus)
void handleDrop(const Item& drop, Equipment& eq, int& money);
void shopMenu(Equipment& eq, int& money);
void runGame();

#endif //GAME_H