#ifndef GAMA_H
#define GAMA_H
#include"Invaders.h"
class Gama:public Invaders{
public:
Gama(sf::Texture * t,std::string ty="gama",float time=5);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind);
virtual void move();
};
#endif
