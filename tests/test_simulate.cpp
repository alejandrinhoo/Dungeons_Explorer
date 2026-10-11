#include <iostream>
#include "Player.h"
#include "Equipment.h"
#include "Item.h"
#include "Game.h"
#include "Config.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Equipment buildGear(Rarity r, int lvl) {
    Equipment gear;
    Item old(HELMET, COMMON, 1);

    gear.equip(Item(HELMET, r, lvl), old);
    gear.equip(Item(VEST, r, lvl), old);
    gear.equip(Item(WEAPON, r, lvl), old);

    return gear;
}

void runScenario(const char* name, const Equipment& gear, int games) {
    int completed = 0;
    long long totalAttempts = 0;

    for (int i = 0; i < games; i++) {
        Player p(BASE_PLAYER_HP, BASE_PLAYER_DAMAGE);
        int result = playDungeon(p, gear, 100, false);

        if (result != -1) {
            completed++;
            totalAttempts += result;
        }
    }

    cout << name << ": " << completed << "/" << games
         << " games completed";

    if (completed > 0) {
        double average = static_cast<double>(totalAttempts) / completed;
        cout << ", average attempts: " << average;
    } else {
        cout << ", average attempts: N/A";
    }

    cout << endl;
}

int main() {
    srand(time(0));

    Equipment none;
    runScenario("Sin equipo", none, 1000);
    runScenario("Comun nivel 1", buildGear(COMMON, 1), 1000);
    runScenario("Comun nivel 5", buildGear(COMMON, 5), 1000);
    runScenario("Epico nivel 5", buildGear(EPIC, 5), 1000);
    runScenario("Epico nivel 10", buildGear(EPIC, 10), 1000);
    runScenario("Legendario nivel 5", buildGear(LEGENDARY, 5), 1000);
    runScenario("Legendario nivel 10", buildGear(LEGENDARY, 10), 1000);

    return 0;
}