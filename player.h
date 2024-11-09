#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
#include "Bullet.cpp"
#include "AddsOn.h"
class Player{
public:
Texture tex;
Sprite sprite;
Bullet * bl;// normal bullet
Bullet *bl_pow[7]; // power_up bullets
AddsOn * Add;
float speed=0.6;
int x,y;
Player(std::string png_path);

void changeTex(std::string png_path);

void get_bullet(Bullet *bl);
void get_bullet(Bullet **&bl_pow);
void get_addson(AddsOn *A);
void fire(Bullet **&power_bullets,Texture &bullet_tex2,Texture &bullet_tex3,Texture &bullet_tex4,Texture &bullet_tex,Texture &bullet_tex7,Texture &bullet_tex6,Texture &bullet_tex5,Player *&p,int &num_pow_bul);
void fire(int &num_bullets,bool &rotate,Bullet **&b,Player *&p,Texture &bullet_tex,Texture &bullet_tex1,Texture &bullet_tex5,Texture &bullet_tex2,Texture &laser,bool catch_fire);
void move(std::string s);
~Player();
};
