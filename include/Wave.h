#ifndef WAVE_H
#define WAVE_H
#include <vector>
#include "Enemy.h"
#include "Player.h"

int firstAlive(const std::vector<Enemy>& enemies);
bool fightWave(Player& p, std::vector<Enemy>& enemies);
std::vector<Enemy> createWave(int level, int sub);

#endif //WAVE_H