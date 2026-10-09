#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Wave.h"
using namespace std;

int main() {
    Player p(100, 50);
    //cout << "HP: " << p.getHP() << endl;
    //cout << "Damage: " << p.getDamage() << endl;

    Player t(100, 20);
    t.takeDamage(70);
    cout << t.getHP() << endl;   // debe dar 30
    t.restoreHP();
    cout << t.getHP() << endl;   // debe dar 100

    /*vector<Enemy> enemies;
    enemies.emplace_back(50,15);
    enemies.emplace_back(50,20);
    enemies.emplace_back(50,30);
    
    if (fightWave(p, enemies)) {
        cout << "You won." << endl;
    } else {
        cout << "Enemies won." << endl;
    }*/
}