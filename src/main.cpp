#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"
using namespace std;

int main() {
    Player p(100, 20);
    //cout << "HP: " << p.getHP() << endl;
    //cout << "Damage: " << p.getDamage() << endl;

    vector<Enemy> enemies;
    enemies.emplace_back(100,15);
    enemies.emplace_back(100,20);
    enemies.emplace_back(100,30);
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
    if (p.isAlive()){
        cout << "You won." << endl;
    } else {
        cout << "Enemies won." << endl;
    }
}