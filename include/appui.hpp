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
  Button* b_sort;
  Button* h_sort;
  Button* i_sort;
  Button* q_sort;
  Button* se_sort;
  Button* sh_sort;

  bool& start_algorithm;
  bool& reset_array;
  std::vector<bool>& current_algorithm;
  
  sf::RectangleShape* h_separator;
  sf::RectangleShape* v_separator;  
  bool h_coloredset;
  void nh_setcolor();
  void h_setcolor();
  void reset_color(int n);
  void a_setcolor();
  int selected_algorithm;
public:
  Appui(bool& s_a,bool& r_a, std::vector<bool>& c_a);
  void render(sf::RenderWindow& w);
  void monitor(sf::RenderWindow& w);
  void selectAlgorithm(int n);
  bool isStartClicked();
  bool isStopClicked();
  bool isResetClicked();
  bool isInsertionClicked();

  
   ~Appui(); 
};

#endif
