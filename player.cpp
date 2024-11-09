#include"player.h"

Player::Player(std::string png_path)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=350;y=600;
sprite.setPosition(x,y);
sprite.setOrigin(101.0f,50.0f);
sprite.setScale(0.75,0.75);
bl=NULL;
Add=NULL;
for(int i=0;i<7;i++)
bl_pow[i]=NULL;
}

void Player::changeTex(std::string png_path){
 tex.loadFromFile(png_path);
 sprite.setTexture(tex);
 sprite.setScale(0.75,0.75);
}

void Player::get_bullet(Bullet *bl)
{
this->bl=bl;
}

void Player::get_bullet(Bullet **&bl_pow){
for(int i=0;i<7;i++){
this->bl_pow[i]=bl_pow[i];
 }
}


void Player::get_addson(AddsOn *A)
{

this->Add=A;
}

void Player::fire(Bullet **&power_bullets,Texture &bullet_tex2,Texture &bullet_tex3,Texture &bullet_tex4,Texture &bullet_tex,Texture &bullet_tex7,Texture &bullet_tex6,Texture &bullet_tex5,Player *&p,int &num_pow_bul){
if(power_bullets==NULL){
   power_bullets=new Bullet*[num_pow_bul];
   power_bullets[0]=new Bullet(&bullet_tex2,p->sprite,3);
   power_bullets[1]=new Bullet(&bullet_tex3,p->sprite,4);
   power_bullets[2]=new Bullet(&bullet_tex4,p->sprite,5);
   power_bullets[3]=new Bullet(&bullet_tex,p->sprite,6);
   power_bullets[4]=new Bullet(&bullet_tex7,p->sprite,7);
   power_bullets[5]=new Bullet(&bullet_tex6,p->sprite,8);
   power_bullets[6]=new Bullet(&bullet_tex5,p->sprite,9);
   get_bullet(power_bullets);
   }
   else{
    Bullet **temp = new Bullet*[num_pow_bul];
    for(int i=0; i<num_pow_bul; i++){
     temp[i] = power_bullets[i];
             }
          num_pow_bul+=7;
       delete [] power_bullets;
      power_bullets=new Bullet*[num_pow_bul];
      for(int i=0; i<num_pow_bul; i++){
      if(i==num_pow_bul-7){
   power_bullets[i]=new Bullet(&bullet_tex2,p->sprite,3);i++;
   power_bullets[i]=new Bullet(&bullet_tex3,p->sprite,4);i++;
   power_bullets[i]=new Bullet(&bullet_tex4,p->sprite,5);i++;
   power_bullets[i]=new Bullet(&bullet_tex,p->sprite,6);i++;
   power_bullets[i]=new Bullet(&bullet_tex7,p->sprite,7);i++;
   power_bullets[i]=new Bullet(&bullet_tex6,p->sprite,8);i++;
   power_bullets[i]=new Bullet(&bullet_tex5,p->sprite,9);
   get_bullet(power_bullets); 
   break;
        }
       power_bullets[i] = temp[i];
      }
      delete [] temp;
      temp = NULL;
   }
}
void Player::fire(int &num_bullets,bool &rotate,Bullet **&b,Player *&p,Texture &bullet_tex,Texture &bullet_tex1,Texture &bullet_tex5,Texture &bullet_tex2,Texture &laser,bool catch_fire){
 if (num_bullets==0){
                num_bullets++;
                b = new Bullet*[num_bullets];
                if(!rotate){
                if(catch_fire)
                b[num_bullets-1] = new Bullet(&laser, p->sprite,0);
                else
                b[num_bullets-1] = new Bullet(&bullet_tex, p->sprite,0);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Right)){
                if(catch_fire)
                b[num_bullets-1] = new Bullet(&laser, p->sprite,1);
                else
                b[num_bullets-1] = new Bullet(&bullet_tex5, p->sprite,1);
                }
                else if(Keyboard::isKeyPressed(Keyboard::Left)){
                if(catch_fire)
                b[num_bullets-1] = new Bullet(&laser, p->sprite,2);
                else
                b[num_bullets-1] = new Bullet(&bullet_tex2, p->sprite,2);
                }
                
                p->get_bullet(b[num_bullets-1]);
            }
            else {
                Bullet **temp = new Bullet*[num_bullets];
                for(int i=0; i<num_bullets; i++){
                    temp[i] = b[i];
                }
                num_bullets++;
                delete [] b;
                b = new Bullet*[num_bullets];
                for(int i=0; i<num_bullets; i++){
                    if(i==num_bullets-1){
                    if(!rotate){
                    if(catch_fire)
                    b[i] = new Bullet(&laser, p->sprite,0);
                    else
                        b[i] = new Bullet(&bullet_tex, p->sprite,0);
                         }
                     else if(Keyboard::isKeyPressed(Keyboard::Right)){
                     if(catch_fire)
                    b[i] = new Bullet(&laser, p->sprite,1);
                    else
                     b[i] = new Bullet(&bullet_tex5, p->sprite,1);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Left)){
                    if(catch_fire)
                    b[i] = new Bullet(&laser, p->sprite,2);
                    else
                   b[i] = new Bullet(&bullet_tex2, p->sprite,2);
                  } 
                        p->get_bullet(b[i]);
                    }
                    else{
                        b[i] = temp[i];
                        if(b[i]!=NULL&&catch_fire==false){
                        if(!rotate&&b[i]->roatated_falg==0 ){
                        b[i]->changeTex(&bullet_tex1);
                        }                 
                        }
                    }
                }
                delete [] temp;
                temp = NULL;
            }
}
void Player::move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l"){
	delta_x=-1;//move the player left
	
	}
else if(s=="r"){
	delta_x=1;//move the player right
	}
if(s=="u"){
	delta_y=-1;
	}
else if(s=="d"){
	delta_y=1;

         }
delta_x*=speed;
delta_y*=speed;

sprite.move(delta_x, delta_y);

}
Player::~Player(){
for(int i=0;i<7;i++){
  if(this->bl_pow[i]!=NULL)
  this->bl_pow[i]=NULL;
 }
 this->Add=NULL;
 this->bl=NULL;
}
