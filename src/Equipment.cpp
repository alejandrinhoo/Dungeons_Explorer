#include "Equipment.h"

Equipment::Equipment()
    : items_{ Item(HELMET, COMMON, 0),
              Item(VEST,   COMMON, 0),
              Item(WEAPON, COMMON, 0) },
      occupied_{ false, false, false } {}

bool Equipment::equip(const Item& item, Item& old) {
    int s = static_cast<int>(item.getSlot());
    bool hadOld = occupied_[s];
    if (hadOld) {
        old = items_[s];          // copia la pieza vieja hacia afuera
    }
    items_[s] = item;             // copia la nueva
    occupied_[s] = true;
    return hadOld;
}

bool Equipment::isEquipped(Slot slot) const {
    return occupied_[static_cast<int>(slot)];
}

const Item& Equipment::get(Slot slot) const {
    return items_[static_cast<int>(slot)];
}

int Equipment::getBonusHP() const {
    int total = 0;
    if (occupied_[HELMET]) total += items_[HELMET].getBonus();
    if (occupied_[VEST])   total += items_[VEST].getBonus();
    return total;
}

int Equipment::getBonusDamage() const {
    return occupied_[WEAPON] ? items_[WEAPON].getBonus() : 0;
}