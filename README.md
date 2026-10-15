# Dungeon Explorer

A turn-based dungeon game that runs in the console, written in C++ (C++11) for the Advanced Programming course (ECMC1015, Yachay Tech University).

**Team:** Javier Alejandro Herdoiza Cagua, Leonel Alexandre Coronel Condoy

## How to play

The player must clear **10 levels**, each with **3 waves** of 1 to 3 random enemies.

- Combat is automatic: the player hits the first living enemy, then every living enemy hits the player.
- Each victory drops a piece of gear (helmet, vest or weapon) from a Box: **equip** it (the old piece is sold) or **sell** it.
- After each level you earn money and can open the **Shop** to upgrade equipped pieces one rarity step (Common, Rare, Epic, Legendary). Legendary pieces cannot be upgraded.
- If you lose a wave x.k you retreat to x.(k-1). Wave x.1 is retried and the level never drops. HP is restored before every fight.
- Enemy HP and damage grow exponentially with the level, so you need gear to progress.

## Build and run

Requires a C++ compiler with C++11 support (`g++`). From the project folder:

```bash
g++ -std=c++11 -Wall -Wextra src/*.cpp -Iinclude -o dungeon.exe
```

Run the game:

```bash
dungeon.exe        # Windows
./dungeon.exe      # Linux / macOS / Git Bash
```

## Project structure

| Component | Files | Description |
|---|---|---|
| Player | `Player.h/.cpp` | Base stats plus gear bonuses, `takeDamage`, `restoreHP` |
| Enemy | `Enemy.h/.cpp` | Enemy with HP and damage |
| Wave | `Wave.h/.cpp` | `createWave` (random count, exponential scaling) and `fightWave` (combat) |
| Game | `Game.h/.cpp`, `main.cpp` | `runGame` (interactive loop), `handleDrop`, `shopMenu`, `playDungeon` (headless run for the simulator) |
| Config | `Config.h` | Constants, `Rarity` and `Slot` enums, rarity multiplier, drop weights, money per level |
| Item | `Item.h/.cpp` | Gear piece: bonus, sell price, description |
| Equipment | `Equipment.h/.cpp` | Three equipment slots and total bonuses |
| Box | `Box.h/.cpp` | Random drops with level-dependent rarity weights |
| Shop | `Shop.h/.cpp`, `Economy.h` | Sell and upgrade pieces |

## Tests and balance simulator

The `tests/` folder has small test programs for Player, Item, Equipment, Box and Shop, and `test_simulate.cpp`, which plays 1000 automatic games per equipment scenario to tune the difficulty:

```bash
g++ -std=c++11 -Wall -Wextra tests/test_simulate.cpp src/Game.cpp src/Wave.cpp src/Player.cpp src/Enemy.cpp src/Item.cpp src/Equipment.cpp src/Box.cpp src/Shop.cpp -Iinclude -o simulate.exe
```

## Status

- [x] Player, Enemy and combat
- [x] Waves, levels and retreat rule
- [x] Items, Equipment and Box (random drops)
- [x] Shop (sell and upgrade) and money per level
- [x] Interactive console game loop
- [ ] Graphical interface
- [ ] Upgrading the level of a piece
- [ ] Save / load
