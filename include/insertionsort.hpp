#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include"algorithm.hpp"

class InsertionSort:public Algorithm
{
public:
   InsertionSort(){};
  ~InsertionSort()=default;
  
    void sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool &start_algorithm) override;
  };
#endif // !DEBUG
