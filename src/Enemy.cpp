#include "Enemy.h"

Enemy::Enemy(int HP, int Damage): HP(HP), Damage(Damage) {}

int Enemy::getHP() const { return HP; }
int Enemy::getDamage() const { return Damage; }
void Enemy::takeDamage(int amount){
    HP -= amount;
    if (HP < 0){HP = 0;}
}
bool Enemy::isAlive() const {
    return HP > 0;
}