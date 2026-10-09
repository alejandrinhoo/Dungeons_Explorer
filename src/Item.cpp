#include "Item.h"

Item::Item(Slot slot, Rarity rarity, int level)
    : slot_{slot}, rarity_{rarity}, level_{level} {}

Slot   Item::getSlot() const   { return slot_; }
Rarity Item::getRarity() const { return rarity_; }
int    Item::getLevel() const  { return level_; }

int Item::getBonus() const {
    int base = (slot_ == WEAPON) ? BASE_BONUS_DAMAGE : BASE_BONUS_HP;
    return base * rarityMultiplier(rarity_) * level_;
}

int Item::getSellPrice() const {
    return BASE_SELL_PRICE * rarityMultiplier(rarity_) * level_;
}

std::string Item::describe() const {
    static const char* slotNames[]   = {"Helmet", "Vest", "Weapon"};
    static const char* rarityNames[] = {"Common", "Rare", "Epic", "Legendary"};
    return std::string(rarityNames[rarity_]) + " " + slotNames[slot_] +
           " (lvl " + std::to_string(level_) + ") +" +
           std::to_string(getBonus()) + (slot_ == WEAPON ? " DMG" : " HP") +
           ", sells for " + std::to_string(getSellPrice());
}