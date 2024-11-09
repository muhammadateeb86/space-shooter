#include"AddsOn.h"

AddsOn::AddsOn(sf::Texture * t,std::string ty){
this->tex=t;
this->type=ty;
sp.setTexture(*tex);
this->x=0;this->y=-20;
sp.setPosition(x,y);
sp.setScale(1.2,1.2);
}
void AddsOn::draw(sf::RenderWindow& window){
window.draw(sp);
}

void AddsOn::move(){

float delta_x=0,delta_y=0;
delta_y=+1;
delta_y*=speed;
sp.move(delta_x,delta_y);

}
