#include"Bullet.h"

Bullet::Bullet(sf::Texture * t,sf::Sprite &s,int flag){
this->roatated_falg=flag;
this->tex=t;
sp.setTexture(*tex);
if(roatated_falg==0||roatated_falg==6){
this->x=(s.getPosition().x)-40;this->y=(s.getPosition().y)-90;}
else if(roatated_falg==1||roatated_falg==9){
this->x=(s.getPosition().x)-7;this->y=(s.getPosition().y)-70;}
else if(roatated_falg==8){
this->x=(s.getPosition().x)-19;this->y=(s.getPosition().y)-80;}
else if(roatated_falg==7){
this->x=(s.getPosition().x)-33;this->y=(s.getPosition().y)-87;}
else if(roatated_falg==4){
this->x=(s.getPosition().x)-85;this->y=(s.getPosition().y)-80;}
else if(roatated_falg==5){
this->x=(s.getPosition().x)-70;this->y=(s.getPosition().y)-85;}
else if(roatated_falg==2||roatated_falg==3){
this->x=(s.getPosition().x)-102;this->y=(s.getPosition().y)-70;}
sp.setPosition(x,y);
sp.setScale(0.75,0.75);
}

void Bullet::changeTex(sf::Texture * t){
 if (t != NULL) { // Add this check
        this->tex = t;
        sp.setTexture(*tex);
    }
}

void Bullet::move(){

float delta_x=0,delta_y=0;
if(roatated_falg==0||roatated_falg==6)
delta_y=-1;
if(roatated_falg==1||roatated_falg==9){
delta_y=-1;
delta_x=+0.5;
}
if(roatated_falg==4){
delta_y=-1;
delta_x=-0.4;
}
if(roatated_falg==5){
delta_y=-1;
delta_x=-0.3;
}
if(roatated_falg==7){
delta_y=-1;
delta_x=+0.3;
}
if(roatated_falg==8){
delta_y=-1;
delta_x=+0.4;
}
if(roatated_falg==2||roatated_falg==3){
delta_y=-1;
delta_x=-0.5;
}
delta_y*=speed;
delta_y*=speed;
sp.move(delta_x,delta_y);

}
