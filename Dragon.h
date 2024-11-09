#ifndef DRAGON_H
#define DRAGON_H
#include"Enemy.h"
class Dragon:public Enemy{
public:
Dragon(sf::Texture * t,std::string ty="dragon",float time=0.5);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind);
virtual void move();
};
#endif
