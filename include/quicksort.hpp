#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include"algorithm.hpp"
class QuickSort:public Algorithm
{
  public:
    QuickSort(){};
    ~QuickSort()=default;

    void sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x, bool& start_algorithm) override;
    
};


#endif // 0#endif
