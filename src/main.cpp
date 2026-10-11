#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Config.h"
#include "Equipment.h"
#include "Item.h"
#include "Game.h"
using namespace std;

int main() {
    srand(time(0));

    Player p(BASE_PLAYER_HP, BASE_PLAYER_DAMAGE);
    Equipment eq;

    Item oldHelmet(HELMET, COMMON, 1);
    Item helmet(HELMET, LEGENDARY, 10);
    eq.equip(helmet, oldHelmet);

    Item oldVest(VEST, COMMON, 1);
    Item vest(VEST, LEGENDARY, 10);
    eq.equip(vest, oldVest);

    Item oldWeapon(WEAPON, COMMON, 1);
    Item weapon(WEAPON, LEGENDARY, 10);
    eq.equip(weapon, oldWeapon);

    int result = playDungeon(p, eq, 100, true);

    if (result != -1) {
        cout << "Dungeon completed in "
             << result << " attempts." << endl;
    } else {
        cout << "You ran out of attempts." << endl;
    }

    return 0;
}