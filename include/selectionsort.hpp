#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include"algorithm.hpp"

class SelectionSort:public Algorithm
{
public:
    SelectionSort(){};
    ~SelectionSort()=default;
   void sort(sf::RenderWindow& w,std::vector<Bar>& array,Appui *ui,float pos_x,bool& start_algorithm) override;
  };

#endif // !DEBUG
