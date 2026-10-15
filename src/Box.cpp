#include "Box.h"
#include "Config.h"
#include <chrono>
#include <vector>

Box::Box(unsigned seed) : gen_(seed) {}

Box::Box()
    : gen_(static_cast<unsigned>(
          std::chrono::steady_clock::now().time_since_epoch().count())) {}

Item Box::open(int level) {
    // Evita pesos negativos fuera de rango
    if (level < 1) level = 1;
    if (level > MAX_LEVEL) level = MAX_LEVEL;

    std::vector<int> weights;
    for (int r = 0; r < 4; ++r)
        weights.push_back(rarityWeight(static_cast<Rarity>(r), level));

    std::discrete_distribution<int> rarityDist(weights.begin(), weights.end());
    std::uniform_int_distribution<int> slotDist(0, 2);

    Rarity rarity = static_cast<Rarity>(rarityDist(gen_));
    Slot   slot   = static_cast<Slot>(slotDist(gen_));
    return Item(slot, rarity, level);
}