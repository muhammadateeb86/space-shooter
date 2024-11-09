#ifndef INVADERS_H
#define INVADERS_H
#include"Enemy.cpp"
class Invaders:public Enemy{
public:
Invaders(sf::Texture * t,std::string ty,float time);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&e,int i)=0;
virtual void move();
virtual ~Invaders();
};
#endif
