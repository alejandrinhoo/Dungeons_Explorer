#ifndef ECONOMY_H
#define ECONOMY_H

#include "Item.h"

// Costo de subir una pieza un escalón de rareza.
// Devuelve -1 si la pieza ya es LEGENDARY (decisión pendiente con Alejo).
inline int upgradeCost(const Item& item) {
    if (item.getRarity() == LEGENDARY) return -1;
    return item.getSellPrice() * 3;
}

#endif