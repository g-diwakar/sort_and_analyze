#ifndef APP_HP
#define APP_HP
#include<vector>
#include<algorithm>
#include<threads.h>
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include"appui.hpp"
#include"bar.hpp"
#include "algorithm.hpp"
#include"bubblesort.hpp"

class App{
private:
  
  unsigned window_width=1020;
  unsigned window_height=780;
  unsigned x_barmargin=2;
  int t_data=100;

  sf::RenderWindow window;

  std::vector<Bar> array;
  std::unique_ptr<Algorithm> sortingAlgorithm;
  float array_width,array_height;
 
  Appui* ui; 
  void initialize();
  void handleEvents();
  void update();
  void mainloop();
  void render();
  void startSort();

public:
  App(); 
  void run(); 
  ~App();
  
};

#endif 
