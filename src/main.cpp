#include <iostream>
#include "Player.h"
#include "Enemy.h"
using namespace std;
int main() {
    Player p(100, 20);
    cout << "HP: " << p.getHP() << endl;
    cout << "Damage: " << p.getDamage() << endl;

    Enemy e(20, 20);
    cout << "Enemy HP: " << e.getHP() << endl;
    cout << "Enemy Damage: " << e.getDamage() << endl;
}