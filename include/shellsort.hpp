#ifndef SHELLSORT_HPP 
#define SHELLSORT_HPP

#include"algorithm.hpp"

class ShellSort:public Algorithm
{
public:
   ShellSort(){};
  ~ShellSort()=default;
  
    void sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool &start_algorithm) override;
  };
#endif // !DEBUG
