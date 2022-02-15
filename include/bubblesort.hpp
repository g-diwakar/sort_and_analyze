#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include"algorithm.hpp"
class BubbleSort:public Algorithm
{
  public:
    BubbleSort(){};
    ~BubbleSort()=default;

    void sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x, bool& start_algorithm) override;
    
};


#endif // 0#endif
