#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"
#include "Config.h"

class Equipment {
public:
    Equipment();

    // Equipa 'item' en su ranura. Si ya había una pieza, la devuelve en 'old'
    // y el resultado es true; si la ranura estaba vacía, devuelve false.
    bool equip(const Item& item, Item& old);

    bool isEquipped(Slot slot) const;
    const Item& get(Slot slot) const;   // solo válido si isEquipped(slot)

    int getBonusHP() const;       // suma de casco + chaleco
    int getBonusDamage() const;   // arma

private:
    Item items_[3];
    bool occupied_[3];
};

#endif