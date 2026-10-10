#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"
using namespace std;

int main() {
    srand(time(0));
    Player p(100, 50);
    int sub = 1;
    int attempts = 0;

    while (sub <= 3 && attempts < 100){
        attempts ++;
        p.restoreHP();
        cout << "subWave " << sub << endl;

        vector<Enemy> enemies = createWave(1, sub);

        if (fightWave(p, enemies)) {
            sub ++;
        } else {
            if (sub > 1){
                sub --;
            }
        }
    }

        if(sub > 3){
            cout << "Dungeon cleared." << endl;
        } else {
            cout << "Gave up." << endl;
        }
}