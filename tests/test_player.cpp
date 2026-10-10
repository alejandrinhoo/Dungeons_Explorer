#include <iostream>
#include "Player.h"

int main() {
    Player p(100, 10);

    std::cout << "inicial: " << p.getHP()
              << " / " << p.getDamage() << "\n";

    p.setBonuses(20, 5);
    p.restoreHP();
    std::cout << "fila 2: " << p.getHP()
              << " / " << p.getDamage() << "\n";

    p.setBonuses(20, 5);
    p.restoreHP();
    std::cout << "fila 3: " << p.getHP()
              << " / " << p.getDamage() << "\n";

    p.setBonuses(0, 0);
    p.restoreHP();
    std::cout << "fila 4: " << p.getHP()
              << " / " << p.getDamage() << "\n";
}