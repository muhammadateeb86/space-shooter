#include"Monster.h"

Monster::Monster(sf::Texture * t,std::string ty,float time):Enemy(t,ty,time){
dir=true;
}

void Monster::attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind){
if(timer>=enemy[ind]->timer){
if (num_bombs==0){
                num_bombs++;
                bo= new Bomb*[num_bombs];
                bo[num_bombs-1] = new Bomb(&en_bomb, (enemy[ind])->sp);  
                bo[num_bombs-1]->sp.setPosition(bo[num_bombs-1]->x+150,bo[num_bombs-1]->y+250);
                Enemy::getbomb(bo[num_bombs-1]);
            }
            else {
                Bomb **temp = new Bomb*[num_bombs];
                for(int i=0; i<num_bombs; i++){
                    temp[i] = bo[i];
                }
                num_bombs++;
                delete [] bo;
                bo= new Bomb*[num_bombs];
                for(int i=0; i<num_bombs; i++){
                    if(i==num_bombs-1){
                        bo[i] = new Bomb(&en_bomb, (enemy[ind])->sp);
                        bo[i]->sp.setPosition(bo[i]->x+100,bo[i]->y+220);
                        Enemy::getbomb(bo[i]);
                    }
                    else{
                        bo[i] = temp[i];  
                        }
                    }
                    delete [] temp;
                    temp = NULL;
                 }
                 timer=0;
                }
                }
                
void Monster::move(){
float delta_x=0,delta_y=0;
if(sp.getPosition().y<=70)
Enemy::move();
else{
if(sp.getPosition().x<380&& dir==true){
 move_enemy="right";
  }
else{
move_enemy="left";
dir=false;
 }
if(sp.getPosition().x<0)
dir=true;
}

if(move_enemy=="right"&&sp.getPosition().x<380){
delta_x=+1;
}
if(move_enemy=="left"&&sp.getPosition().x>0){
delta_x=-1;
}
delta_y*=speed;
delta_x*=speed;
sp.move(delta_x,delta_y);
}
