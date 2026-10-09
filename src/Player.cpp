#include "Player.h"
using namespace std;

Player::Player(int HP, int Damage): HP(HP), Damage(Damage) {}

int Player::getHP() const {return HP;}
int Player::getDamage() const {return Damage;}
