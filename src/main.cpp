#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"
#include "Config.h"
#include "Equipment.h"
#include "Item.h"
#include "Game.h"
using namespace std;

int main() {
    srand(time(0));

    Player p(BASE_PLAYER_HP, BASE_PLAYER_DAMAGE);

    Equipment eq;

    Item old(HELMET, COMMON, 1);
    Item vest(VEST, LEGENDARY, 10);
    eq.equip(vest, old);

    Item first(WEAPON, COMMON, 1);
    Item weapon(WEAPON, LEGENDARY, 10);
    eq.equip(weapon, first);

    int result = playDungeon(p, eq, 100, true);
    if (result != -1){
        cout << "Dungeon completed" << endl;
    } else{
        cout << "You ran out of attempts" << endl;
    }

    return 0;
}