#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include"Bomb.cpp"
class Enemy{
public:
Bomb *b;
float timer;
string move_enemy;
std::string type;
sf::Texture * tex;
sf::Sprite sp;
float speed=0.2;
int x,y;

Enemy(sf::Texture * t,std::string ty,float time);
void draw(sf::RenderWindow& window);
void getbomb(Bomb *bo);
virtual void attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&e,int ind)=0;
virtual void move();

virtual ~Enemy();
};
#endif
