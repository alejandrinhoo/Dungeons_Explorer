#ifndef SHOP_H
#define SHOP_H

#include "Item.h"

namespace Shop {

// Dinero que da vender la pieza.
int sell(const Item& item);

// true si la pieza no es legendaria y alcanza el dinero.
bool canUpgrade(const Item& item, int money);

// Si se puede, descuenta el costo de 'money', escribe la pieza mejorada
// en 'result' y devuelve true. Si no, no toca nada y devuelve false.
bool upgrade(const Item& item, int& money, Item& result);

}

#endif