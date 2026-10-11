#include "Game.h"
#include "Wave.h"
#include "Config.h"
#include <iostream>

using namespace std;

int playDungeon(Player& p, const Equipment& eq, int maxAttempts, bool verbose){
    int sub = 1;
    int level = 1;
    int attempts = 0;

    while (level <= MAX_LEVEL && attempts < maxAttempts){
            attempts ++;

            p.setBonuses(eq.getBonusHP(), eq.getBonusDamage());
            p.restoreHP();

            if (verbose){
                cout << "Level: " << level << " - Wave " << sub << endl;
            }

            vector<Enemy> enemies = createWave(level, sub);

            if (fightWave(p, enemies, verbose)) {
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
        return attempts;
    } else {
        return -1;
    }
}