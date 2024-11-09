#include"Alpha.h"


Alpha::Alpha(sf::Texture * t,std::string ty,float time):Invaders(t,ty,time){
}

void Alpha::attack(float &timer,Bomb**&bo,int &num_bombs,sf::Texture &en_bomb,Enemy**&enemy,int ind){
if(timer>=enemy[ind]->timer){
if (num_bombs==0){
                num_bombs++;
                bo= new Bomb*[num_bombs];
                bo[num_bombs-1] = new Bomb(&en_bomb, (enemy[ind])->sp);  
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
                        Enemy::getbomb(bo[i]);
                    }
                    else{
                        bo[i] = temp[i];  
                        }
                    }
                    delete [] temp;
                    temp = NULL;
                 }
                }
             }
void Alpha::move(){
Invaders::move();
}
