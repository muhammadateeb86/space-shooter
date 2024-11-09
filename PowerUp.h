#ifndef POWERUP_H
#define POWERUP_H
#include"AddsOn.h"
class PowerUp:public AddsOn{
public:
Texture *tex;
Sprite sp;
float speed=0.6;
int x,y;
PowerUp(sf::Texture * t,std::string ty="PowerUp");
};
#endif
