#ifndef BETA_H
#define BETA_H
#include"Invaders.h"
class Beta:public Invaders{
public:
Beta(sf::Texture * t,std::string ty="beta",float time=3);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind);
virtual void move();
};
#endif
