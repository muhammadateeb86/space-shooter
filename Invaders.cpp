#include"Invaders.h"

Invaders::Invaders(sf::Texture * t,std::string ty,float time):Enemy(t,ty,time){
}

void Invaders::move(){

float delta_x=0,delta_y=0;
if(move_enemy=="\0"){
Enemy::move();
}
if((move_enemy=="down"&&sp.getPosition().y<220)){
Enemy::move();
}
if(move_enemy=="up"&&sp.getPosition().y>20){
delta_y=-1;
}

delta_y*=speed;
delta_x*=speed;
sp.move(delta_x,delta_y);

}

Invaders::~Invaders(){

}
