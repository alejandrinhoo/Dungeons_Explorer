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
using namespace std;

int main() {
    srand(time(0));

    Player p(BASE_PLAYER_HP, BASE_PLAYER_DAMAGE);

    int sub = 1;
    int level = 1;
    int attempts = 0;

    Equipment eq;

    Item old(HELMET, COMMON, 1);
    Item vest(VEST, LEGENDARY, 10);
    eq.equip(vest, old);

    Item first(WEAPON, COMMON, 1);
    Item weapon(WEAPON, LEGENDARY, 10);
    eq.equip(weapon, first);

    while (level <= MAX_LEVEL && attempts < 100){
        attempts ++;

        p.setBonuses(eq.getBonusHP(), eq.getBonusDamage());
        p.restoreHP();

        cout << "Level: " << level << " - Wave " << sub << endl;

        vector<Enemy> enemies = createWave(level, sub);

        if (fightWave(p, enemies, false)) {
            sub ++;

            if (sub > SUBLEVELS_PER_LEVEL) {
                level ++;
                sub = 1;
            }
        } else {
            if (sub > 1){
                sub --;
            }
        }
    }

    if (level > MAX_LEVEL){
        cout << "Dungeon completed." << endl;
    } else {
        cout << "You ran out of attempts." << endl;
    }
    return 0;
}