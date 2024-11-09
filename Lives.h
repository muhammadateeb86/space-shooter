#ifndef LIVES_H
#define LIVES_H
#include"AddsOn.h"
class Lives:public AddsOn{
public:
Texture *tex;
Sprite sp;
float speed=0.6;
int x,y;
Lives(sf::Texture * t,std::string ty="Life");
};
#endif
