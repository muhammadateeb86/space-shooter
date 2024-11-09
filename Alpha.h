#ifndef ALPHA_H
#define ALPHA_H
#include"Invaders.cpp"
class Alpha:public Invaders{
public:
Alpha(sf::Texture * t,std::string ty="alpha",float time=2);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind);
virtual void move();
};
#endif
