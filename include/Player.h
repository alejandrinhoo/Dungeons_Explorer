#ifndef PLAYER_H
#define PLAYER_H
class Player{
public:
    Player(int HP, int Damage);
    int getHP() const;
    int getDamage() const;
    void takeDamage(int amount);
    bool isAlive() const;
private:
    int HP;
    int Damage;
};
#endif // PLAYER_H