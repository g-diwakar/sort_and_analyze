#ifndef ANALYZEUI_HPP
#define ANALYZEUI_HPP
#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>

class Analyze_ui
{
private:
  struct Coordinates
  {
        int x;
        int  y;
  };
  std::vector<Coordinates> b_sort;
  std::vector<Coordinates> d_sort;
  std::vector<Coordinates> h_sort;
  std::vector<Coordinates> iquick_sort;
  std::vector<Coordinates> i_sort;
  std::vector<Coordinates> li_sort;
  std::vector<Coordinates> m_sort;
  std::vector<Coordinates> q_sort;
  std::vector<Coordinates> r_sort;
  std::vector<Coordinates> re_sort;
  std::vector<Coordinates> se_sort;
  std::vector<Coordinates> sh_sort;

  std::vector<bool> active_algorithm;
  std::vector<sf::Color> color_algorithm;
  
  sf::RectangleShape graph;
  sf::RectangleShape addPixels(float x_pos,float y_pos,sf::Color color);
  std::vector<sf::Image> points;

  void readFiles();
  void draw_point(sf::RenderWindow &w, int n,std::vector<Coordinates>& data );
public:
  Analyze_ui();
  void render(sf::RenderWindow& w );
  void monitor(sf::RenderWindow& w);
  float get_relative_x(float x);
  float get_relative_y(float y);
  };

#endif
