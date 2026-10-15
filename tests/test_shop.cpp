#include <iostream>
#include "Shop.h"
#include "Equipment.h"

int main() {
    int money = 100;
    Item rare(WEAPON, RARE, 3);
    Item result(WEAPON, COMMON, 1);

    std::cout << "Vender rara lvl3: " << Shop::sell(rare) << "\n";     // 30

    bool ok = Shop::upgrade(rare, money, result);
    std::cout << "Mejora ok? " << ok << "  dinero: " << money << "\n"; // 1  10
    std::cout << result.describe() << "\n";   // Epic Weapon (lvl 3) +24 DMG, sells for 60

    bool ok2 = Shop::upgrade(result, money, result);   // sin dinero (10 < 180)
    std::cout << "Mejora sin dinero? " << ok2 << "  dinero: " << money << "\n"; // 0  10

    Item leg(VEST, LEGENDARY, 10);
    int rich = 9999;
    std::cout << "Mejorar legendaria? "
              << Shop::upgrade(leg, rich, result) << "\n";           // 0

    // Mejorar una pieza equipada
    Equipment eq;
    Item discard(WEAPON, COMMON, 1);
    eq.equip(rare, discard);
    int money2 = 500;
    Item better(WEAPON, COMMON, 1);
    if (Shop::upgrade(eq.get(WEAPON), money2, better))
        eq.equip(better, discard);
    std::cout << "DMG tras mejorar: " << eq.getBonusDamage() << "\n"; // 24
    return 0;
}