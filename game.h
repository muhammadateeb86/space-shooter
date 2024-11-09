
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <cmath>
using namespace std;
#include "menu.cpp"
#include "Alpha.cpp"
#include "Beta.cpp"
#include "Gama.cpp"
#include "player.cpp"
#include "Dragon.cpp"
#include "Monster.cpp"
#include "Danger.cpp"
#include "Fire.cpp"
#include "PowerUp.cpp"
#include "Lives.cpp"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
sf::Font bebas;
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
// add other game attributes
Enemy**enemy;
int num_enemy;
Game();
void wave1(Enemy **&enemy,int &num_enemy);
void wave2(Enemy **&enemy,int &num_enemy);
void wave3(Enemy **&enemy,int &num_enemy);
void wave4(Enemy **&enemy,int &num_enemy);
void chk_enemy(int &num_enemy,Enemy **&enemy,bool &distroyed,int &lvl,Enemy **&temp,bool &move,bool &allow,Texture &aa,Texture &bb,Texture &ga);
void adding_addson(float &adds_delay,AddsOn *&spice,Player *&p,Texture &f,Texture &life,Texture &power,Texture &danger);
 void dragon_appear(float &dragon_delay,bool &disappear,Enemy **&enemy,Texture &dragon,Player *&p,float &d_m_fire,Bomb **&drag_fire,int &num_fire,Texture &laser);
void monster_appear(float &dragon_delay,bool &disappear_mon,Enemy **&enemy,Texture &m,Player *&p,float &d_m_fire,Bomb **&monster_fire,int &num_mon_fire,Texture &mon_las);
void bullet_del(bool &bullet,int &num_bullets,Bullet **&b);
void enemy_dist(bool &bullet,bool &allow,bool &disappear,bool &disappear_mon,int &num_bullets,int &num_enemy,Bullet**&b,Enemy**&enemy,int &lvl,int &score);
void update_player(Player *&p);
void attack_invaders(bool &move,bool &disappear,bool &disappear_mon,int  &lvl,int &num_enemy,Enemy**&enemy,float &alpha_delay,float &beta_delay,float &gama_delay,Bomb **&bo,int &num_bombs,Texture &en_bomb);
void  col_sp_bomb(int &num_bombs,Bomb**&bo,Player *&p,bool &power_mode,int &life_count,float &birth_delay);
void col_sp_en(bool &allow,bool &disappear,bool &disappear_mon,int &num_enemy,Enemy**&enemy,Player *&p,int &life_count,float &birth_delay); 
void start_game();

~Game();

};

