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