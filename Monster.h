#ifndef MONSTER_H
#define MONSTER_H
#include"Enemy.h"
class Monster:public Enemy{
public:
bool dir;
Monster(sf::Texture * t,std::string ty="monster",float time=2);

virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind);
virtual void move();
};
#endif
