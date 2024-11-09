#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
class Bullet{
public:
Texture *tex;
Sprite sp;
float speed=0.6;
int x,y;
int roatated_falg=0;
Bullet(sf::Texture * t,sf::Sprite &s,int flag);
void changeTex(sf::Texture * t);
void move();
};
#endif
