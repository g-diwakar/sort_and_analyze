#ifndef APPUI_HPP
#define APPUI_HPP

#include"button.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class Appui
{
private:
  Button* start;
  Button* stop;
  Button* reset;

  bool& start_algorithm;
  bool& reset_array;
  
  sf::RectangleShape* separator;
    
  bool h_coloredset;
  void nh_setcolor();
  void h_setcolor();
public:
  Appui(bool& s_a,bool& r_a);
  void render(sf::RenderWindow& w);
  void monitor(sf::RenderWindow& w);

  bool isStartClicked();
  bool isStopClicked();
  bool isResetClicked();

  
   ~Appui(); 
};

#endif
