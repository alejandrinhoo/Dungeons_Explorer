#ifndef PLAYER_H
#define PLAYER_H
class Player{
public:
    Player(int HP, int Damage);
    int getHP() const;
    int getDamage() const;
    void takeDamage(int amount);
    bool isAlive() const;
    void restoreHP();
private:
    int HP;
    int maxHP;
    int Damage;
};
#endif // PLAYER_H