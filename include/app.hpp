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
#include"insertionsort.hpp"
#include"selectionsort.hpp"
#include"heapsort.hpp"
#include"quicksort.hpp"
#include"menuui.hpp"
#include"analyzeui.hpp"
#include"shellsort.hpp" 

class App{
private:
  
  unsigned window_width=1020;
  unsigned window_height=780;
  unsigned x_barmargin=0;
  int t_data=100;


  bool a_menu;
  bool a_visualize;
  bool a_analyze;

  sf::RenderWindow window;

  std::vector<Bar> array;
  std::unique_ptr<Algorithm> sortingAlgorithm;
  std::vector<bool> current_algorithm;
  float array_width,array_height;

  bool reset_array;
  bool set_algorithm;
 
  Appui* ui;
  MainMenu* M_ui;
  Analyze_ui* A_ui;
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
