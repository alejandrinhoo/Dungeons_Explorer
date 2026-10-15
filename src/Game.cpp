#include "Game.h"
#include "Wave.h"
#include "Config.h"
#include "Box.h"
#include "Shop.h"
#include "Economy.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int playDungeon(Player& p, const Equipment& eq, int maxAttempts, bool verbose){
    int sub = 1;
    int level = 1;
    int attempts = 0;

    while (level <= MAX_LEVEL && attempts < maxAttempts){
        attempts ++;

        p.setBonuses(eq.getBonusHP(), eq.getBonusDamage());
        p.restoreHP();

        if (verbose){
            cout << "Level: " << level << " - Wave " << sub << endl;
        }

        vector<Enemy> enemies = createWave(level, sub);

        if (fightWave(p, enemies, verbose)) {
            sub ++;

            if (sub > SUBLEVELS_PER_LEVEL) {
                level ++;
                sub = 1;
            }
        } else {
            if (sub > 1){
                sub --;
            }
        }
    }

    if (level > MAX_LEVEL){
        return attempts;
    } else {
        return -1;
    }
}

// Reads an integer between minValue and maxValue. Repeats until valid.
// If the input ends (EOF) it returns minValue so the program never loops forever.
static int readOption(int minValue, int maxValue){
    int option;
    while (true){
        cout << "> ";
        if (cin >> option && option >= minValue && option <= maxValue){
            return option;
        }
        if (cin.eof()){
            return minValue;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid option. Enter a number between "
             << minValue << " and " << maxValue << "." << endl;
    }
}

// The player found a piece: equip it (old piece is sold) or sell it.
void handleDrop(const Item& drop, Equipment& eq, int& money){
    cout << "You found: " << drop.describe() << endl;

    Slot slot = drop.getSlot();
    if (eq.isEquipped(slot)){
        cout << "Currently equipped: " << eq.get(slot).describe() << endl;
    }

    cout << "1) Equip (the old piece is sold)   2) Sell" << endl;
    int option = readOption(1, 2);

    if (option == 1){
        Item old(HELMET, COMMON, 1);
        if (eq.equip(drop, old)){
            int gained = Shop::sell(old);
            money += gained;
            cout << "Equipped. Old piece sold for " << gained << "." << endl;
        } else {
            cout << "Equipped." << endl;
        }
    } else {
        int gained = Shop::sell(drop);
        money += gained;
        cout << "Sold for " << gained << "." << endl;
    }
}

// True if at least one equipped piece can be upgraded with the current money.
static bool canUpgradeAnything(const Equipment& eq, int money){
    for (int s = 0; s < 3; s++){
        Slot slot = static_cast<Slot>(s);
        if (eq.isEquipped(slot) && Shop::canUpgrade(eq.get(slot), money)){
            return true;
        }
    }
    return false;
}

// Shop: upgrade equipped pieces one rarity step with money.
void shopMenu(Equipment& eq, int& money){
    static const char* names[] = {"Helmet", "Vest", "Weapon"};

    while (true){
        cout << "\n=== SHOP === Money: " << money << endl;
        for (int s = 0; s < 3; s++){
            cout << (s + 1) << ") " << names[s] << ": ";
            if (!eq.isEquipped(static_cast<Slot>(s))){
                cout << "(empty)" << endl;
                continue;
            }
            const Item& item = eq.get(static_cast<Slot>(s));
            cout << item.describe();
            int cost = upgradeCost(item);
            if (cost < 0){
                cout << " | max rarity";
            } else {
                cout << " | upgrade cost: " << cost;
            }
            cout << endl;
        }
        cout << "0) Leave shop" << endl;

        int option = readOption(0, 3);
        if (option == 0){
            return;
        }

        Slot slot = static_cast<Slot>(option - 1);
        if (!eq.isEquipped(slot)){
            cout << "Nothing equipped there." << endl;
            continue;
        }

        Item better(HELMET, COMMON, 1);
        Item old(HELMET, COMMON, 1);
        if (Shop::upgrade(eq.get(slot), money, better)){
            eq.equip(better, old);
            cout << "Upgraded: " << better.describe() << endl;
        } else {
            cout << "Cannot upgrade (not enough money or already legendary)." << endl;
        }
    }
}

// Full game: fight waves, get a box after each victory, shop after each level.
void runGame(){
    Player p(BASE_PLAYER_HP, BASE_PLAYER_DAMAGE);
    Equipment eq;
    Box box;
    int money = 0;
    int level = 1;
    int sub = 1;

    cout << "=== DUNGEON EXPLORER ===" << endl;
    cout << "Beat " << MAX_LEVEL << " levels of " << SUBLEVELS_PER_LEVEL
         << " waves each. Win fights to get gear." << endl;

    while (level <= MAX_LEVEL){
        if (cin.eof()){
            cout << "\nInput closed. Goodbye." << endl;
            return;
        }

        p.setBonuses(eq.getBonusHP(), eq.getBonusDamage());
        p.restoreHP();

        vector<Enemy> enemies = createWave(level, sub);

        cout << "\n--- Level " << level << " - Wave " << sub << " ---" << endl;
        cout << "You: HP " << p.getHP() << ", Damage " << p.getDamage()
             << " | Money: " << money << endl;
        cout << "Enemies: " << enemies.size() << " (HP " << enemies[0].getHP()
             << ", damage " << enemies[0].getDamage() << " each)" << endl;

        if (fightWave(p, enemies, false)){
            cout << "Victory! HP left: " << p.getHP() << endl;
            handleDrop(box.open(level), eq, money);

            sub++;
            if (sub > SUBLEVELS_PER_LEVEL){
                int reward = levelMoney(level);
                money += reward;
                cout << "\nLevel " << level << " completed! +" << reward
                     << " money." << endl;
                level++;
                sub = 1;
                if (level <= MAX_LEVEL){
                    shopMenu(eq, money);
                }
            }
        } else {
            cout << "Defeat! The enemies were too strong." << endl;
            if (sub > 1){
                sub--;
                cout << "You retreat to wave " << sub << "." << endl;
            } else {
                cout << "You must try this wave again." << endl;
            }
            if (canUpgradeAnything(eq, money)){
                cout << "You can afford an upgrade!" << endl;
                shopMenu(eq, money);
            }
        }
    }

    cout << "\n*** You beat the dungeon! ***" << endl;
}
