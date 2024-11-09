#ifndef DANGER_H
#define DANGER_H
#include"AddsOn.cpp"
class Danger:public AddsOn{
public:
Texture *tex;
Sprite sp;
float speed=0.6;
int x,y;
Danger(sf::Texture * t,std::string ty="Danger");
};
#endif
