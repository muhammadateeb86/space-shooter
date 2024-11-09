#include"Enemy.h"

Enemy::Enemy(sf::Texture * t,std::string ty,float time){
this->tex=t;
this->type=ty;
timer=time;
sp.setTexture(*tex);
this->x=150;this->y=20;
sp.setPosition(x,y);
sp.setScale(0.45,0.45);
b=NULL;
move_enemy="\0";
}
void Enemy::draw(sf::RenderWindow& window){
window.draw(sp);
}

void Enemy::getbomb(Bomb *bo){
this->b=bo;
}

void Enemy::move(){
float delta_x=0,delta_y=0;
delta_y=+1;
delta_y*=speed;
sp.move(delta_x,delta_y);

}

Enemy::~Enemy(){

}
