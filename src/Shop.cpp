#include "Shop.h"
#include "Economy.h"

namespace Shop {

int sell(const Item& item) {
    return item.getSellPrice();
}

bool canUpgrade(const Item& item, int money) {
    int cost = upgradeCost(item);
    return cost >= 0 && money >= cost;
}

bool upgrade(const Item& item, int& money, Item& result) {
    if (!canUpgrade(item, money)) return false;
    money -= upgradeCost(item);
    Rarity next = static_cast<Rarity>(item.getRarity() + 1);
    result = Item(item.getSlot(), next, item.getLevel());
    return true;
}

}