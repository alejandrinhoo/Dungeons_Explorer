#include <iostream>
#include "Equipment.h"

int main() {
    Equipment eq;
    std::cout << "Inicial  HP: " << eq.getBonusHP()
              << "  DMG: " << eq.getBonusDamage() << "\n";   // 0, 0

    Item old(HELMET, COMMON, 1);    // contenedor para la pieza devuelta

    Item helmet1(HELMET, COMMON, 1);
    bool r1 = eq.equip(helmet1, old);
    std::cout << "Casco 1, reemplazo? " << r1 << "\n";        // 0
    std::cout << "HP: " << eq.getBonusHP() << "\n";           // 10

    Item helmet2(HELMET, EPIC, 2);
    bool r2 = eq.equip(helmet2, old);
    std::cout << "Casco 2, reemplazo? " << r2 << "\n";        // 1
    std::cout << "Pieza vieja: " << old.describe() << "\n";
    std::cout << "HP: " << eq.getBonusHP() << "\n";           // 10*4*2 = 80

    Item vest(VEST, RARE, 3);
    Item weapon(WEAPON, EPIC, 3);
    eq.equip(vest, old);
    eq.equip(weapon, old);
    std::cout << "HP total: " << eq.getBonusHP() << "\n";      // 80 + 60 = 140
    std::cout << "DMG total: " << eq.getBonusDamage() << "\n"; // 24
    return 0;
}