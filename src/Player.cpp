#include "Player.h"
using namespace std;

Player::Player(int HP, int Damage): HP(HP), maxHP(HP), Damage(Damage), bonusHP(0), bonusDamage(0) {}

int Player::getHP() const {return HP;}
int Player::getDamage() const {return Damage + bonusDamage;}
void Player::takeDamage(int amount) {
    HP -= amount;
    if (HP < 0) {HP = 0;}
}
bool Player::isAlive() const {return HP > 0;}
void Player::restoreHP(){HP = maxHP + bonusHP;}
void Player::setBonuses(int hpBonus, int dmgBonus){
    bonusHP = hpBonus;
    bonusDamage = dmgBonus;
}