#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
using namespace std;
int main() {
    Player p(100, 29);
    cout << "HP: " << p.getHP() << endl;
    cout << "Damage: " << p.getDamage() << endl;
}