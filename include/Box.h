#ifndef BOX_H
#define BOX_H

#include <random>
#include "Item.h"

class Box {
public:
    explicit Box(unsigned seed);
    Box();                      // semilla basada en el reloj

    Item open(int level);       // no es const: avanza el generador

private:
    std::mt19937 gen_;
};

#endif