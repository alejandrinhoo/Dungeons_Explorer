#include <iostream>
#include "Item.h"

int main() {
    Item a(HELMET, COMMON, 1);
    Item b(WEAPON, EPIC, 3);
    Item c(VEST, LEGENDARY, 10);

    std::cout << a.describe() << "\n";
    std::cout << b.describe() << "\n";
    std::cout << c.describe() << "\n";
}