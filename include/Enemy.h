#ifndef ENEMY_H
#define ENEMY_H
class Enemy{
public:
    Enemy(int HP, int Damage);
    int getHP() const;
    int getDamage() const;
private:
int HP;
int Damage;
};

#endif //ENEMY_H