#include <iostream>
#include "Wave.h"
#include <cmath>
using namespace std;

const int BASE_ENEMY_HP = 30;
const int BASE_ENEMY_DAMAGE = 2;
const double ENEMY_GROWTH = 1.40;

int firstAlive(const vector<Enemy>& enemies){
    for (size_t i = 0; i < enemies.size(); i++){
        if (enemies[i].isAlive()){
            return (int)i;
        }
    }
    return -1;
}

bool fightWave(Player& p, vector<Enemy>& enemies, bool verbose){
    while (p.isAlive() && firstAlive(enemies) != -1){
        int target = firstAlive(enemies);
        enemies[target].takeDamage(p.getDamage());
        if (verbose){
            cout << "Player attacks " << target + 1 << " for " << p.getDamage() << " damage." << endl;
        }
        for (size_t j = 0; j < enemies.size(); j++){
            if (enemies[j].isAlive() && p.isAlive()){
                p.takeDamage(enemies[j].getDamage());
                if (verbose){
                    cout << "Enemy " << j+1 << " attacks Player for " << enemies[j].getDamage() << " damage." << endl;
                }
            }
        }
        if (verbose){
            cout << "Player HP: " << p.getHP() << endl;
        }
        for (size_t i = 0; i < enemies.size(); i++){
            if (verbose){
                cout << "Enemy " << i+1 << " HP: " << enemies[i].getHP() << endl;
            }
        }
    }
    return p.isAlive();
}

vector<Enemy> createWave(int level, int sub){
    int count = (rand() % 3) + 1;
    int hp = static_cast<int>(BASE_ENEMY_HP * std::pow(ENEMY_GROWTH, level)) + 2*sub;
    int dmg = static_cast<int>(BASE_ENEMY_DAMAGE * std::pow(ENEMY_GROWTH, level));

    vector<Enemy> wave;
    for (int i = 0; i < count; i++){
        wave.emplace_back(hp, dmg);
    }
    return wave;
}