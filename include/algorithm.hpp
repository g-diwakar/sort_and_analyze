#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include"bar.hpp"
#include"appui.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include<chrono>
#include<thread>
class Algorithm
{
protected:
  void swap(Bar& a, Bar& b);
  bool isGreater(Bar&a, Bar&b);
  bool isLesser(Bar&a, Bar& b);
public:
  Algorithm(){};
  ~Algorithm()=default;

  virtual void sort(sf::RenderWindow&w,std::vector<Bar>& array,Appui* ui, float posx,bool& start_algorithm)=0;
  void render(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x);
  void delay();

  };


#endif 
