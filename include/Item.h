#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Config.h"

class Item {
public:
    Item(Slot slot, Rarity rarity, int level);

    Slot   getSlot() const;
    Rarity getRarity() const;
    int    getLevel() const;
    int    getBonus() const;      // HP si es casco/chaleco, daño si es arma
    int    getSellPrice() const;
    std::string describe() const;

private:
    Slot   slot_;
    Rarity rarity_;
    int    level_;
};

#endif