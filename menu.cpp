#include"menu.h"

Menu::Menu()
{
//constructors body
bg_texture.loadFromFile("img/menu.jpg");
background.setTexture(bg_texture);
background.setScale(1, 1.5);
bebas.loadFromFile("Text_file/Bebas-Regular.ttf");   // location of font file
 my_text.setFont(bebas);
    my_text.setString("1.Start Game");
    my_text.setPosition(250,200);
    my_text.setFillColor(sf::Color::White);
    my_text.setCharacterSize(20);
    // instructions
    my_text1.setFont(bebas);
    my_text1.setString("2.Instructions");
    my_text1.setPosition(250,250);
    my_text1.setFillColor(sf::Color::White);
    my_text1.setCharacterSize(20);
    // high score
    my_text2.setFont(bebas);
    my_text2.setString("3.High Scores");
    my_text2.setPosition(250,300);
    my_text2.setFillColor(sf::Color::White);
    my_text2.setCharacterSize(20);   
}


bool Menu::display_menu()

{
  
 sf::RenderWindow window(sf::VideoMode(650,650), "Menue");
 
  // start game option
   
    while (window.isOpen()){
         sf::Event event;
         while (window.pollEvent(event)) {                   //Event is occurring - until the game is in running state
            if (event.type == sf::Event::Closed){                   //If cross/close is clicked/pressed
                window.close();
                }
          else if (event.key.code == sf::Keyboard::Num1){
                  window.close();
                  return 1;
                  
          }
          else if (event.key.code == sf::Keyboard::Num2){ 
          sf::RenderWindow window(sf::VideoMode(650,650), "Instructions");
          
          }
          else if (event.key.code == sf::Keyboard::Num3){ 
          
          }
        }
               window.clear(sf::Color::Black); //clears the screen
               window.draw(background);
               window.draw( my_text);
               window.draw( my_text1);
               window.draw( my_text2);
               window.display(); 
        
      
  }   
                   return 0;
}
