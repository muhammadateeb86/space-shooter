#include <SFML/Graphics.hpp>
class Menu{
public:
sf::Font bebas;
sf::Text my_text,my_text1,my_text2;
sf::Sprite background; //Game background sprite
sf::Texture bg_texture;
Menu();
bool display_menu();


};
