#include <iostream>
#include "Box.h"
#include "Economy.h"

void sample(Box& box, int level) {
    int count[4] = {0, 0, 0, 0};
    for (int i = 0; i < 100; ++i)
        ++count[box.open(level).getRarity()];
    std::cout << "Nivel " << level
              << "  Common:" << count[COMMON]
              << "  Rare:" << count[RARE]
              << "  Epic:" << count[EPIC]
              << "  Legendary:" << count[LEGENDARY] << "\n";
}

int main() {
    Box box(12345);          // semilla fija: resultados repetibles
    sample(box, 1);
    sample(box, 5);
    sample(box, 10);

    Item rare(WEAPON, RARE, 3);
    Item leg(VEST, LEGENDARY, 10);
    std::cout << "Dinero nivel 4: " << levelMoney(4) << "\n";
    std::cout << "Mejorar rara lvl3: " << upgradeCost(rare) << "\n";
    std::cout << "Mejorar legendaria: " << upgradeCost(leg) << "\n";
    return 0;
}