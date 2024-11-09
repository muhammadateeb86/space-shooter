#include"Dragon.h"

Dragon::Dragon(sf::Texture * t,std::string ty,float time):Enemy(t,ty,time){}
void Dragon::attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind){
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
                
void Dragon::move(){
Enemy::move();
}
