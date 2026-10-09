#ifndef CONFIG_H
#define CONFIG_H

// Enums acordados para la interfaz
enum Rarity { COMMON, RARE, EPIC, LEGENDARY };
enum Slot { HELMET, VEST, WEAPON };

// Valores iniciales y constantes
const int BASE_PLAYER_HP = 100;
const int BASE_PLAYER_DAMAGE = 10;

const int MAX_LEVEL = 10;
const int SUBLEVELS_PER_LEVEL = 3;

// Bonos base por ranura, se multiplican por rareza y nivel
const int BASE_BONUS_HP = 10;      // casco y chaleco
const int BASE_BONUS_DAMAGE = 2;   // arma
const int BASE_SELL_PRICE = 5;

// Multiplicador por rareza: COMMON=1, RARE=2, EPIC=4, LEGENDARY=8
inline int rarityMultiplier(Rarity r) {
    switch (r) {
        case COMMON:    return 1;
        case RARE:      return 2;
        case EPIC:      return 4;
        case LEGENDARY: return 8;
    }
    return 1; // evita el warning de -Wall
}

#endif