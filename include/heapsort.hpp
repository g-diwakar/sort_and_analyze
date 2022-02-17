#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include"algorithm.hpp"

class HeapSort:public Algorithm
{
public:
    HeapSort(){};
    ~HeapSort()=default;
   void sort(sf::RenderWindow& w,std::vector<Bar>& array,Appui *ui,float pos_x,bool& start_algorithm) override;
  };

#endif 
