#include <iostream>
#include "Wave.h"
using namespace std;

int firstAlive(const vector<Enemy>& enemies){
    for (size_t i = 0; i < enemies.size(); i++){
        if (enemies[i].isAlive()){
            return (int)i;
        }
    }
    return -1;
}

bool fightWave(Player& p, vector<Enemy>& enemies){
    while (p.isAlive() && firstAlive(enemies) != -1){
        int target = firstAlive(enemies);
        enemies[target].takeDamage(p.getDamage());
        cout << "Player attacks " << target + 1 << " for " << p.getDamage() << " damage." << endl;
        for (size_t j = 0; j < enemies.size(); j++){
            if (enemies[j].isAlive() && p.isAlive()){
                p.takeDamage(enemies[j].getDamage());
                cout << "Enemy " << j+1 << " attacks Player for " << enemies[j].getDamage() << " damage." << endl;
            }
        }
        cout << "Player HP: " << p.getHP() << endl;
        for (size_t i = 0; i < enemies.size(); i++){
            cout << "Enemy " << i+1 << " HP: " << enemies[i].getHP() << endl;
        }
    }
    return p.isAlive();
}