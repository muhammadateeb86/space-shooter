#include"game.h"
/*************************************************/
Game::Game()
{
bebas.loadFromFile("Text_file/Bebas-Regular.ttf");   // location of font file
p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
enemy=NULL;
num_enemy=12;
Menu m;
if(m.display_menu())
start_game();
}
/*************************************************/
// wave 1
void Game::wave1(Enemy **&enemy,int &num_enemy){
 float space=0.0; // used for spacing
    for(int i=0;i<num_enemy-2;i++){
        if(i<=3){
        enemy[i]->sp.setPosition((enemy[i]->sp.getPosition().x+space),enemy[i]->sp.getPosition().y-300);
        space+=100.0;
        }
        if(i==3)
        space=0;
        if(i>=4&&i<=7){
        enemy[i]->sp.setPosition((enemy[i]->sp.getPosition().x+space),enemy[i]->sp.getPosition().y+200.0-300);
        space+=100.0;
        }
        if(i==8){
        enemy[i]->sp.setPosition(enemy[i]->sp.getPosition().x,enemy[i]->sp.getPosition().y+100.0-300);
        }
        if(i==9){
        enemy[i]->sp.setPosition(enemy[3]->sp.getPosition().x,enemy[i]->sp.getPosition().y+100.0-300);
        }
        }
}
/*******************************************************/
// wave 2
void Game::wave2(Enemy **&enemy,int &num_enemy){
    const int numEnemies = num_enemy-2;
    const float centerPosX = 325.0f;
    const float centerPosY = 150.0f;
    const float radius = 170.0f;
    const float angleIncrement = 360.0f / numEnemies;
for (int i = 0; i < numEnemies; ++i) {
        // Calculate the angle in radians
        float angle = i * angleIncrement * 3.14159f / 180.0f;

        // Calculate the enemy position
        float enemyPosX = centerPosX + radius * std::cos(angle);
        float enemyPosY = centerPosY + radius * std::sin(angle);

        // Set the enemy position
        enemy[i]->sp.setPosition(enemyPosX, enemyPosY);
    }
for(int i=0;i<num_enemy-2;i++){
enemy[i]->sp.setPosition((enemy[i]->sp.getPosition().x),enemy[i]->sp.getPosition().y-300);
}
}
/*******************************************************/
// wave 3
void Game::wave3(Enemy **&enemy,int &num_enemy){
float space=90;// used for spacing
for(int i=0;i<num_enemy-2;i++){
if(i==0)
enemy[i]->sp.setPosition((enemy[i]->sp.getPosition().x+120),enemy[i]->sp.getPosition().y);
if(i>=1&&i<=3){
enemy[i]->sp.setPosition((enemy[i-1]->sp.getPosition().x-80),enemy[i-1]->sp.getPosition().y+80);
}
else if(i==4){
enemy[i]->sp.setPosition((enemy[0]->sp.getPosition().x+80),enemy[0]->sp.getPosition().y+80);
}
else if(i==5||i==6){
enemy[i]->sp.setPosition((enemy[i-1]->sp.getPosition().x+80),enemy[i-1]->sp.getPosition().y+80);
 }
 else if(i>=7&&i<=9){
 enemy[i]->sp.setPosition((enemy[3]->sp.getPosition().x+space),enemy[3]->sp.getPosition().y);
 space+=150;
 }
}
for(int i=0;i<num_enemy-2;i++){
enemy[i]->sp.setPosition((enemy[i]->sp.getPosition().x),enemy[i]->sp.getPosition().y-300);
}
}
/*****************************************************/
 void Game::adding_addson(float &adds_delay,AddsOn *&spice,Player *&p,Texture &f,Texture &life,Texture &power,Texture &danger){
  /********************making of adds on*******************/ 
    
        if(adds_delay>=(10+(rand()%20))){
        float choice_adds_on=(rand()%4)+1;
        int x=5+(rand()%680);
        if(spice==NULL&&choice_adds_on==1){
        spice=new Fire(&f);
        if(p!=NULL){
        p-> get_addson(spice);
        p->Add->sp.setPosition(x,p->Add->sp.getPosition().y);
         }
        }
        if(spice==NULL&&choice_adds_on==2){
        spice=new PowerUp(&power);
        p-> get_addson(spice);
        p->Add->sp.setPosition(x,p->Add->sp.getPosition().y);
        } 
        if(spice==NULL&&choice_adds_on==3){
        spice=new Lives(&life);
        if(p!=NULL){
        p-> get_addson(spice);
        p->Add->sp.setPosition(x,p->Add->sp.getPosition().y);
        }
           } 
        if(spice==NULL&&choice_adds_on==4){
        spice=new Danger(&danger);
        if(p!=NULL){
        p-> get_addson(spice);
        p->Add->sp.setPosition(x,p->Add->sp.getPosition().y);
         } 
        }
        adds_delay=0.0;
           }   
     /******************************************************/  
}
void Game::chk_enemy(int &num_enemy,Enemy **&enemy,bool &distroyed,int &lvl,Enemy **&temp,bool &move,bool &allow,Texture &aa,Texture &bb,Texture &ga){
 for(int i=0;i<num_enemy-2;i++){
      if(enemy[i]==NULL){
      distroyed=true;
      }
      else{
       distroyed=false;
       break;
      }
      }
     if(distroyed){
     lvl++;
     for(int i=0;i<num_enemy-2;i++){
     if(temp[i]->type=="alpha"){

     enemy[i]=new Alpha(&aa);
     }
     else if(temp[i]->type=="beta"){

     enemy[i]=new Beta(&bb);
     }
     else if(temp[i]->type=="gama"){
       
     enemy[i]=new Gama(&ga);
     }
     
     }
       if(lvl==2){
     wave2(enemy,num_enemy);
     move=true;
     allow=false;
     }  
       if(lvl==3){
     wave3(enemy,num_enemy);
     move=true;
     allow=false;
     } 
     distroyed=false;
     }
 }
 void Game::dragon_appear(float &dragon_delay,bool &disappear,Enemy **&enemy,Texture &dragon,Player *&p,float &d_m_fire,Bomb **&drag_fire,int &num_fire,Texture &laser){
  if(dragon_delay>=15){
     disappear=true;
     if(enemy[10]==NULL){
     enemy[10]=new Dragon(&dragon);
     enemy[10]->sp.setPosition(enemy[10]->x,enemy[10]->y-200);}
     if(enemy[10]->sp.getPosition().y<=70)
     enemy[10]->move();
     else if(p!=NULL){
     enemy[10]->attack(d_m_fire,drag_fire,num_fire,laser,enemy,10);
     }
     }
     if(dragon_delay>=20){  
       delete  enemy[10];
       enemy[10]=NULL;
       disappear=false;     
     }
    
 }
 void Game::monster_appear(float &dragon_delay,bool &disappear_mon,Enemy **&enemy,Texture &m,Player *&p,float &d_m_fire,Bomb **&monster_fire,int &num_mon_fire,Texture &mon_las){
   if(dragon_delay>=30){
     disappear_mon=true;
     if(enemy[11]==NULL){
      enemy[11]=new Monster(&m);
    enemy[11]->sp.setPosition(enemy[11]->x,enemy[11]->y-200);}
     enemy[11]->move();
     if(p!=NULL&&enemy[11]->sp.getPosition().y>=70){
     enemy[11]->attack(d_m_fire,monster_fire,num_mon_fire,mon_las,enemy,11);
     }
     }
     if(dragon_delay>=35){   
        dragon_delay=0;
        delete  enemy[11];
       enemy[11]=NULL;
     disappear_mon=false;     
     }
 
   }
void Game::bullet_del(bool &bullet,int &num_bullets,Bullet **&b){
           if (bullet){
        
            for(int i=0; i<num_bullets; i++){
                if (b[i] == NULL){
                    continue;
                }
                 else if (b[i]->sp.getPosition().y < 0.0){
                    delete b[i];
                    b[i] = NULL;
                }
                 else if (b[i]->sp.getPosition().x < 0.0){
                    delete b[i];
                    b[i] = NULL;
                }
                 else if (b[i]->sp.getPosition().x > 700.0f){
                    delete b[i];
                    b[i] = NULL;
                }
                 
            else if(b[i]!= NULL)
            b[i]->move();
        }
        }
 }
void Game::enemy_dist(bool &bullet,bool &allow,bool &disappear,bool &disappear_mon,int &num_bullets,int &num_enemy,Bullet**&b,Enemy**&enemy,int &lvl,int &score){
         if(bullet==true && allow==true && disappear==false && disappear_mon==false)
        for(int i=0; i<num_bullets; i++)
        for(int j=0;j<num_enemy-2;j++){
        if( b[i]!= NULL&&enemy[j]!=NULL)
        if(b[i]->sp.getGlobalBounds().left < enemy[j]->sp.getGlobalBounds().left + enemy[j]->sp.getGlobalBounds().width &&
        b[i]->sp.getGlobalBounds().left + b[i]->sp.getGlobalBounds().width > enemy[j]->sp.getGlobalBounds().left &&
        b[i]->sp.getGlobalBounds().top < enemy[j]->sp.getGlobalBounds().top + enemy[j]->sp.getGlobalBounds().height &&
        b[i]->sp.getGlobalBounds().top + b[i]->sp.getGlobalBounds().height >  enemy[j]->sp.getGlobalBounds().top){
        if(enemy[j]->type=="alpha"){
        score+=10*lvl;
         }
        else if(enemy[j]->type=="beta"){
           score+=20*lvl;
          }
        else if(enemy[j]->type=="gama"){
             score+=30*lvl;
          }
        delete b[i];
        b[i] = NULL;
        delete enemy[j];
        enemy[j] = NULL;
        }
        }
  }
  
void Game::update_player(Player *&p){
  if(p!=NULL){
        if(p->sprite.getPosition().x<0){
        p->sprite.setPosition(650.0f,p->sprite.getPosition().y);
        }
          if(p->sprite.getPosition().y>670.0f){
        p->sprite.setPosition(p->sprite.getPosition().x,0.0f);
        }
         if(p->sprite.getPosition().x>700.0f){
        p->sprite.setPosition(0.0f,p->sprite.getPosition().y);
        }
        if(p->sprite.getPosition().y<-50){
        p->sprite.setPosition(p->sprite.getPosition().x,670.0f);
        }
        }
 }
 void Game::attack_invaders(bool &move,bool &disappear,bool &disappear_mon,int  &lvl,int &num_enemy,Enemy**&enemy,float &alpha_delay,float &beta_delay,float &gama_delay,Bomb **&bo,int &num_bombs,Texture &en_bomb){
   if(!move && disappear==false && disappear_mon==false && (lvl==1 ||lvl==2||lvl==3 )){
       for(int i=0;i<num_enemy-2;i++){ 
       if( enemy[i]!=NULL){
       if(enemy[i]->sp.getPosition().y<=20.54)
       enemy[i]->move_enemy="down";
       else if(enemy[i]->sp.getPosition().y>=220)
       enemy[i]->move_enemy="up"; 
        if(enemy[i]->type=="alpha"){
       enemy[i]->attack(alpha_delay,bo,num_bombs,en_bomb,enemy,i);
        }
       else if(enemy[i]->type=="beta"){
       enemy[i]->attack(beta_delay,bo,num_bombs,en_bomb,enemy,i);
       }
       else if(enemy[i]->type=="gama"){
      enemy[i]->attack(gama_delay,bo,num_bombs,en_bomb,enemy,i);
       } 
      enemy[i]->move();  
      }  
     }    
    }
  }
  void Game::col_sp_bomb(int &num_bombs,Bomb**&bo,Player *&p,bool &power_mode,int &life_count,float &birth_delay){
   for(int i=0; i<num_bombs; i++){
                if (bo[i] == NULL){
                    continue;
                }
              if(p!=NULL && power_mode==false){
              if(bo[i]->sp.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
    bo[i]->sp.getGlobalBounds().left + bo[i]->sp.getGlobalBounds().width >  p->sprite.getGlobalBounds().left &&
    bo[i]->sp.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
   bo[i]->sp.getGlobalBounds().top + bo[i]->sp.getGlobalBounds().height > p->sprite.getGlobalBounds().top){
        delete bo[i];
        bo[i] = NULL;
        delete p;
        p = NULL;
        --life_count;
        birth_delay=0.0f;
         }
        } 
                else if (bo[i]->sp.getPosition().y>620){
                    delete bo[i];
                    bo[i] = NULL;
                }
                 if(bo[i]!= NULL){
            bo[i]->move();
            }        
        }
   }
 void Game::col_sp_en(bool &allow,bool &disappear,bool &disappear_mon,int &num_enemy,Enemy**&enemy,Player *&p,int &life_count,float &birth_delay){
  if( allow==true && disappear==false && disappear_mon==false)
       for(int i=0;i<num_enemy;i++){
       if(enemy[i]!=NULL && p!=NULL){
       if(enemy[i]->sp.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
    enemy[i]->sp.getGlobalBounds().left + enemy[i]->sp.getGlobalBounds().width >  p->sprite.getGlobalBounds().left &&
    enemy[i]->sp.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
   enemy[i]->sp.getGlobalBounds().top + enemy[i]->sp.getGlobalBounds().height > p->sprite.getGlobalBounds().top){
           delete enemy[i];
           enemy[i]=NULL;
           delete p;
           p=NULL;
           life_count--;
           birth_delay=0.0f;
     }
       
        }
       }
   }  
void Game::start_game()
{  //////////////////////////////////////
   srand(time(0));  // generating the randon numbers 
  /*** ADDS ON ***/
  int score=0;
    sf::Text my_text;  // score board
    my_text.setFont(bebas);
    my_text.setString("Score");
    my_text.setPosition(600,10);
    my_text.setFillColor(Color::White);
    my_text.setCharacterSize(20);
        Texture f;     // texture of addson fire
        f.loadFromFile("img/PNG/Power-ups/bolt_gold.png");
        Texture power;   // texture of addson power up
        power.loadFromFile("img/PNG/Power-ups/powerupYellow_star.png");
        Texture danger;   // texture of addson danger
        danger.loadFromFile("img/PNG/Power-ups/bolt_bronze.png");
        Texture life;     // texture of addson life
        life.loadFromFile("img/PNG/Power-ups/pill_red.png");
        // adds on 
        AddsOn *spice=NULL;  // pointer of adds on for polymorphism
      /////////////////bomb//////////////////
        Texture en_bomb;   // bomb for the enemy
        en_bomb.loadFromFile("img/enemy_laser.png");
        Bomb **bo = NULL;
        int num_bombs = 0;
   ///////////////////////////////////////
   Texture aa;  //alpha
   aa.loadFromFile("img/enemy_1.png");
   Texture bb;  // beta
   bb.loadFromFile("img/enemy_2.png");
   Texture ga;  // gama
   ga.loadFromFile("img/enemy_3.png");
    /////////Dragon Texture & laser /////////////
   Texture dragon;
   dragon.loadFromFile("img/dragon2.png");
   Texture laser;
   laser.loadFromFile("img/Laser1.png");
   Texture laser1;  // for space ship fire
   laser1.loadFromFile("img/PNG/Effects/fire17.png");
   Bomb **drag_fire = NULL;
   int num_fire = 0;
   //////////////////////////////////////////
   Texture m;
   m.loadFromFile("img/monster1.png");
   Texture mon_las;
   mon_las.loadFromFile("img/mons.png");
   Bomb **monster_fire = NULL;
   int num_mon_fire=0;
   ////////////////////////////////////////// 
   /*******loading the enemies***********/
    enemy=new Enemy*[num_enemy];
    enemy[10]=NULL;
    enemy[11]=NULL;
    for(int i=0;i<3;i++)
    enemy[i]=new Alpha(&aa);
    for(int i=3;i<6;i++)
    enemy[i]=new Beta(&bb);
    for(int i=6;i<10;i++)
    enemy[i]=new Gama(&ga);  
      // copying the enemy 
      Enemy **temp=new Enemy*[num_enemy-2] ;
        for(int i=0;i<num_enemy-2;i++){
     if(enemy[i]->type=="alpha"){
     temp[i]=new Alpha(&aa);
     }
     else if(enemy[i]->type=="beta"){
     temp[i]=new Beta(&bb);
     }
     else if(enemy[i]->type=="gama"){
     temp[i]=new Gama(&ga);
     }
     }
      wave1(enemy,num_enemy);
   ////////////////////////////////////////////
   // first texture for bullet
   Texture bullet_tex;
   bullet_tex.loadFromFile("img/PNG/Lasers/laserBlue01.png");
   //  second texture for bullet
   Texture bullet_tex1;
   bullet_tex1.loadFromFile("img/PNG/Lasers/laserRed01.png");
   /////////////////////////////////////////////////////////////
    Texture bullet_tex2;
   bullet_tex2.loadFromFile("img/image(1).png");
   
    Texture bullet_tex3;
   bullet_tex3.loadFromFile("img/image(3).png");
   
    Texture bullet_tex4;
   bullet_tex4.loadFromFile("img/image(4).png"); // rotated bullets
                                                                
    Texture bullet_tex5;
   bullet_tex5.loadFromFile("img/image.png");
   
    Texture bullet_tex6;
   bullet_tex6.loadFromFile("img/image(2).png");
   
    Texture bullet_tex7;
   bullet_tex7.loadFromFile("img/image(5).png");
   
   ////////////power up bullets/////////////////////////////////
   Bullet **power_bullets=NULL;
   int num_pow_bul=7;
  
   //////////////////////space ship bullets////////////////////
   Bullet **b = NULL;
   int num_bullets = 0;
   //////////////////////////////////////////////////////////
   RenderWindow window(VideoMode(650, 650), title);
   Clock clock;
   float timer=0;
   float bullet_delay=0,adds_delay=0,gama_delay=0,beta_delay=0,alpha_delay=0,dragon_delay=0,birth_delay=0,power_delay=0,d_m_fire=0;
   int lvl=1,life_count=3;
   bool bullet=false,rotate=0,move=1, allow=0,disappear=0,distroyed=0,disappear_mon=0,power_mode=0,catch_fire=0;
   while (window.isOpen())
   {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        bullet_delay+=time;
        adds_delay+=time;
        gama_delay+=time;
        beta_delay+=time;
        alpha_delay+=time;
        dragon_delay+=time;
        birth_delay+=time;
        power_delay+=time;
        d_m_fire+=time;
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed){
                window.close();
            }
                if (e.type == Event::KeyReleased)
      {
            rotate=false;
      }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)&&p!=NULL){
           p->move("l");
           }
        else if (Keyboard::isKeyPressed(Keyboard::Right)&&p!=NULL){
           p->move("r");
           }
        else if (Keyboard::isKeyPressed(Keyboard::Up)&&p!=NULL){
           p->move("u");
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)&&p!=NULL){
           p->move("d");
        }
        
         if (Keyboard::isKeyPressed(Keyboard::Left)&&p!=NULL&&power_mode==0)
         {
         if(Keyboard::isKeyPressed(Keyboard::Up)){
            p->changeTex("img/New Project (2).png");
            p->speed=0.21;
            p->move("l");
            p->move("u");
            rotate=true;
            p->sprite.setScale(1,1);
        }
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right)&&Keyboard::isKeyPressed(Keyboard::Up)&&p!=NULL&&power_mode==0)){
            p->changeTex("img/New Project (1).png");
           p->move("r");
           p->move("u");
              p->speed=0.21;
            rotate=true;
            p->sprite.setScale(1,1);
        }
    
         if ((Keyboard::isKeyPressed(Keyboard::M) && bullet_delay>0.25&&p!=NULL&&power_mode==0)||(catch_fire==true&&p!=NULL&&bullet_delay>0.25)){
            p->fire(num_bullets,rotate,b,p,bullet_tex,bullet_tex1,bullet_tex5,bullet_tex2,laser1,catch_fire);
            bullet = true;
            bullet_delay = 0;
        }
            
         adding_addson(adds_delay,spice,p,f,life,power,danger);                   
         // checking all enemies are destroyed or not 
         chk_enemy(num_enemy,enemy,distroyed,lvl,temp,move,allow,aa,bb,ga);
       // dragon appearance
       dragon_appear(dragon_delay,disappear,enemy,dragon,p,d_m_fire,drag_fire,num_fire,laser);
      // monster appearance
       monster_appear(dragon_delay,disappear_mon,enemy,m,p,d_m_fire,monster_fire,num_mon_fire,mon_las);
        // update bullet positions and check for deletion
        bullet_del(bullet,num_bullets,b); 
        // collision of bullet and enemy
        enemy_dist(bullet,allow,disappear,disappear_mon,num_bullets,num_enemy,b,enemy,lvl,score);           
        // update the player positions
        update_player(p);       
       // spaceship rotation            
       if(!rotate&&p!=NULL){
        p->changeTex("img/player_ship.png");
        p->sprite.setScale(0.75,0.75);
        p->speed=0.3;
       }      
       // enemy move
       if((lvl==2||lvl==3||lvl==1)){
       float stop=20;
       if(lvl==2)
       stop=190;
       if(enemy[0]!=NULL && enemy[0]->sp.getPosition().y<stop && move==true){
        for(int i=0;i<num_enemy-2;i++)
        enemy[i]->move();
        }
        else{
        move=false;
        allow=true;
        }
       }
      // attack invaders and move
  attack_invaders(move,disappear,disappear_mon,lvl,num_enemy,enemy,alpha_delay,beta_delay,gama_delay,bo,num_bombs,en_bomb);  
     // collision of enemy bomb and space ship
       col_sp_bomb(num_bombs,bo,p,power_mode,life_count,birth_delay);       
       // collision of enemy and space ship 
       col_sp_en(allow,disappear,disappear_mon,num_enemy,enemy,p,life_count,birth_delay);            
       // birth of space ship 
        if(p==NULL&&life_count>0&&birth_delay>2.0f){
        p=new Player("img/player_ship.png");
        }
               
        // dragon_fire
                  if(drag_fire!=NULL){
           for(int i=0;i<num_fire;i++){
                if (drag_fire[i] == NULL){
                    continue;
                }
                 else if (drag_fire[i]->sp.getPosition().y>=620){
                           delete drag_fire[i];
                           drag_fire[i]=NULL;
                }
                else if (p!=NULL&&(drag_fire[i]->sp.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
    drag_fire[i]->sp.getGlobalBounds().left + drag_fire[i]->sp.getGlobalBounds().width >  p->sprite.getGlobalBounds().left &&
    drag_fire[i]->sp.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
   drag_fire[i]->sp.getGlobalBounds().top + drag_fire[i]->sp.getGlobalBounds().height > p->sprite.getGlobalBounds().top)){
                           delete  p;
                           p=NULL;
                           life_count--;
                          birth_delay=0.0f;
                }
             if(drag_fire[i]!= NULL){
            drag_fire[i]->move();
            }
        }
        }
        // mon fire
            if(monster_fire!=NULL){
           for(int i=0;i<num_mon_fire;i++){
                if (monster_fire[i] == NULL){
                    continue;
                }
                 else if (monster_fire[i]->sp.getPosition().y>=620){
                           score+=40;
                           delete  monster_fire[i];
                           monster_fire[i]=NULL;
                }
                else if (p!=NULL&&(monster_fire[i]->sp.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
    monster_fire[i]->sp.getGlobalBounds().left + monster_fire[i]->sp.getGlobalBounds().width >  p->sprite.getGlobalBounds().left &&
    monster_fire[i]->sp.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
   monster_fire[i]->sp.getGlobalBounds().top + monster_fire[i]->sp.getGlobalBounds().height > p->sprite.getGlobalBounds().top)){
                           delete  p;
                           p=NULL;
                           life_count--;
                          birth_delay=0.0f;
                }
             if(monster_fire[i]!= NULL){
            monster_fire[i]->move();
            }
        }
        }
        // adds on del && move
        if(spice!=NULL){
        spice->move();
        if (spice->sp.getPosition().y>630){
        delete spice;
        spice=NULL;
        }
        else if(p!=NULL&&(spice->sp.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width &&
    spice->sp.getGlobalBounds().left + spice->sp.getGlobalBounds().width >  p->sprite.getGlobalBounds().left &&
    spice->sp.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height &&
   spice->sp.getGlobalBounds().top + spice->sp.getGlobalBounds().height > p->sprite.getGlobalBounds().top)){
    if(spice->type=="Life")
     ++life_count;
    if(spice->type=="Danger"){
    delete p;
    p=NULL;
    --life_count;
    }
    if(spice->type=="PowerUp"){
   power_mode=true;
   power_delay=0;
  
    }
    if(spice->type=="Fire"){
    catch_fire=true;
    power_delay=0;
    }
      delete spice;
      spice=NULL;
     }
        }
    //////////////////////   
    if(power_mode==true&&bullet_delay>0.25&&p!=NULL){
     p->fire(power_bullets,bullet_tex2,bullet_tex3,bullet_tex4,bullet_tex,bullet_tex7,bullet_tex6,bullet_tex5,p,num_pow_bul); 
     bullet_delay=0;
     }
     
     if(power_mode==true && power_bullets!=NULL)
       for(int i=0;i<num_pow_bul;i++){
       if (power_bullets[i] != NULL){
                 if (power_bullets[i]->sp.getPosition().y < 0.0){
                    delete power_bullets[i];
                    power_bullets[i] = NULL;
                }
                 else if (power_bullets[i]->sp.getPosition().x < 0.0){
                    delete power_bullets[i];
                    power_bullets[i] = NULL;
                }
                 else if (power_bullets[i]->sp.getPosition().x > 700.0f){
                    delete power_bullets[i];
                    power_bullets[i] = NULL;
                }
                 
            else if(power_bullets[i]!= NULL){
             power_bullets[i]->move();}
           }
        }
           
    if(power_mode==true&&power_delay>=5){
    power_mode=false;
            if(power_bullets!=NULL){
          for(int i=0;i<num_pow_bul;i++){
           if( power_bullets[i]!=NULL)
           delete power_bullets[i];
           power_bullets[i]=NULL;
            }
           delete [] power_bullets;
            power_bullets=NULL;
           }
           num_pow_bul=7;
    }
    if(catch_fire==true && power_delay>=5){
    catch_fire=false; 
     }
        // collision of power bullets and enemy
        if(power_bullets!=NULL && allow==true && disappear==false&&enemy!=NULL)
        for(int i=0; i<num_pow_bul; i++){
        for(int j=0;j<num_enemy-2;j++){
        if( power_bullets[i]!= NULL&&enemy[j]!=NULL)
        if(power_bullets[i]->sp.getGlobalBounds().left < enemy[j]->sp.getGlobalBounds().left + enemy[j]->sp.getGlobalBounds().width &&
        power_bullets[i]->sp.getGlobalBounds().left + power_bullets[i]->sp.getGlobalBounds().width > enemy[j]->sp.getGlobalBounds().left &&
        power_bullets[i]->sp.getGlobalBounds().top < enemy[j]->sp.getGlobalBounds().top + enemy[j]->sp.getGlobalBounds().height &&
        power_bullets[i]->sp.getGlobalBounds().top + power_bullets[i]->sp.getGlobalBounds().height >  enemy[j]->sp.getGlobalBounds().top){
        delete power_bullets[i];
        power_bullets[i] = NULL;
        delete enemy[j];
        enemy[j] = NULL;
        }
        }
        }
       //////////////////////////////////////////////////////////
       if(timer>=2)
       alpha_delay=0;
        if(timer>=3)
       beta_delay=0;
        if(timer>=5){
       gama_delay=0; 
       timer=0;
       } 
       if(life_count==0||lvl==4){
       Menu m;
       if(m.display_menu()){
       window.close();
       start_game();}
       else{
       window.close();
        }
       
       }
 // displaying score
Text text;
text.setFont(bebas);
text.setString(to_string(score));
text.setPosition(600,30);                            // dispay at the end as these are dynamic values
text.setCharacterSize(20);  
text.setFillColor(Color::White);
text.setCharacterSize(15);
       /////////////////////// 
        window.clear(Color::Black);
        window.draw(background);
        window.draw(my_text);
        window.draw(text);
        if(p!=NULL){
        window.draw(p->sprite);
        }
        if(disappear==false&&enemy!=NULL&&disappear_mon==false)
        for(int i=0;i<num_enemy-2;i++){
        if(enemy[i]!=NULL)
        enemy[i]->draw(window);
        }
        if(disappear==true&&enemy[10]!=NULL){
        enemy[10]->draw(window);
        for(int i=0;i<num_fire;i++)
        if(drag_fire[i]!=NULL)
        window.draw(drag_fire[i]->sp);
        }
        if(disappear_mon==true&&enemy[11]!=NULL){
        enemy[11]->draw(window);
        for(int i=0;i<num_mon_fire;i++)
        if(monster_fire[i]!=NULL)
        window.draw(monster_fire[i]->sp);
        }
        
        if (bullet&&b!=NULL){
            for(int i=0; i<num_bullets; i++){
                if (b[i] == NULL){
                    continue;
                }
                else{
                    window.draw(b[i]->sp);
          }
         }
        }
           
            for(int i=0; i<num_bombs; i++){
                if (bo[i] == NULL){
                    continue;
                }
                else{
                    window.draw(bo[i]->sp);
          }
         }
         if (power_mode){
          if(power_bullets!=NULL)
         for(int i=0; i<num_pow_bul; i++){
          if(power_bullets[i]!=NULL){
          window.draw(power_bullets[i]->sp);
           }
          }
         }
         
       if(spice!=NULL){
       window.draw(spice->sp);
       }
	window.display();  //Displying all the sprites
        
    } 
     // freeing the memories
     /*********************************************************/      
            if(b!=NULL){
            for(int i=0;i<num_bullets;i++){
            if((b[i])==NULL)
            continue;
            else{
            delete  b[i];b[i]=NULL;
            }
            }
            delete [] b; 
            b=NULL;
            }
            if(bo!=NULL){
            for(int i=0;i<num_bombs;i++){
            if((bo[i])==NULL)
            continue;
            else{
            delete  bo[i];bo[i]=NULL;
            }
            }
            delete [] bo; 
            b=NULL;
            }
            if(drag_fire!=NULL){
            for(int i=0;i<num_fire;i++){
            if((drag_fire[i])==NULL)
            continue;
            else{
            delete  drag_fire[i];
            drag_fire[i]=NULL;
            }
            }
            delete [] drag_fire; 
            drag_fire=NULL;
            }
                if(monster_fire!=NULL){
            for(int i=0;i<num_mon_fire;i++){
            if((monster_fire[i])==NULL)
            continue;
            else{
            delete  monster_fire[i];
            monster_fire[i]=NULL;
            }
            }
            delete [] monster_fire; 
            monster_fire=NULL;
            }
            if(temp!=NULL){
            for(int i=0;i<num_enemy-2;i++){
            if((temp[i])==NULL)
            continue;
            else{
            delete temp[i];temp[i]=NULL;
            }
            }
            delete [] temp; 
            temp=NULL;
            }
         // adds on del
           if(spice!=NULL){
           delete spice;
           spice=NULL;
           }
           
           // power up deletion
         if(power_bullets!=NULL){
          for(int i=0;i<num_pow_bul;i++){
           if( power_bullets[i]!=NULL){
           delete power_bullets[i];
           power_bullets[i]=NULL;}
            }
           delete [] power_bullets;
            power_bullets=NULL;
           }
        /*********************************************************/              
}

Game::~Game(){
if(p!=NULL){
delete p;
p=NULL;}

if(enemy!=NULL){
for(int i=0;i<num_enemy-2;i++){
if( enemy[i]!=NULL){
delete enemy[i];
enemy[i]=NULL;}
}
delete [] enemy;
enemy=NULL;
}
}
