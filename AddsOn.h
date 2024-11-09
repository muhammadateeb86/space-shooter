#ifndef ADDSON_H
#define ADDSON_H
#include <SFML/Graphics.hpp>
class AddsOn{
public:
std::string type;
sf::Texture * tex;
sf::Sprite sp;
float speed=0.2;
int x,y;
AddsOn(sf::Texture * t,std::string ty);
void draw(sf::RenderWindow& window);
void move();
};
#endif
