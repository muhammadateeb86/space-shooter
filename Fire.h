#ifndef FIRE_H
#define FIRE_H
#include"AddsOn.h"
class Fire:public AddsOn{
public:
Texture *tex;
Sprite sp;
float speed=0.6;
int x,y;
Fire(sf::Texture * t,std::string ty="Fire");
};
#endif
