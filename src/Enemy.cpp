#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int HP, int Damage): HP(HP), Damage(Damage) {}

int Enemy::getHP() const { return HP; }
int Enemy::getDamage() const { return Damage; }