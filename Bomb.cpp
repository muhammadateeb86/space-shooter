#include"Bomb.h"

Bomb::Bomb(sf::Texture * t,sf::Sprite &s){
this->tex=t;
sp.setTexture(*tex);
this->x=(s.getPosition().x+9);this->y=(s.getPosition().y+25);
sp.setPosition(x,y);
sp.setScale(0.75,0.75);
}

void Bomb::move_dragon(float x, float y) {
    /*float bomb_X = sp.getPosition().x;
    float bomb_Y = sp.getPosition().y;

    // Calculate the direction towards the target position (space ship)
    float delta_x = x - bomb_X;
    float delta_y = y- bomb_Y;

    // Calculate the distance between the bomb and the target position
    float distance = std::pow((delta_x * delta_x + delta_y * delta_y),0.5);

    // Normalize the direction
    float directionX = delta_x / distance;
    float directionY = delta_y / distance;

    // Calculate the movement amount based on the normalized direction and speed
    float move_X = (directionX * speed);
    float move_Y = (directionY * speed);

    // Move the bomb towards the target position
    sp.move(move_X, move_Y);*/
}

void Bomb::move(){
float delta_x=0,delta_y=0;
delta_y=+1;
delta_y*=speed;
sp.move(delta_x,delta_y);
}
