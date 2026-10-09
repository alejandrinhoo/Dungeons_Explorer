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

    while (e.isAlive() && p.isAlive()){
        e.takeDamage(p.getDamage()); //Turno del jugador
        cout << "Player attacks for " << p.getDamage() << " damage." << endl;
        if (e.isAlive()) {
            p.takeDamage(e.getDamage()); //Turno del enemigo
            cout << "Enemy attacks player for " << e.getDamage() << " damage." << endl;
        }
    cout << "Player HP: " << p.getHP() << endl;
    cout << "Enemy HP: " << e.getHP() << endl;
    }
    if (e.isAlive()) {
        cout << "Enemy won" << endl;
    } else {
        cout << "You won" << endl;
    }
}
