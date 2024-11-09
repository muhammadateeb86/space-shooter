#ifndef BOMB_H
#define BOMB_H
#include<SFML/Graphics.hpp>
class Bomb{
public:
sf::Texture *tex;
sf::Sprite sp;
float speed=0.4;
int x,y;

Bomb(sf::Texture * t,sf::Sprite &s);
void move_dragon(float x, float y);
void move();
};
#endif
