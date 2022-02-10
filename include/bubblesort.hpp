#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include"algorithm.hpp"
class BubbleSort:public Algorithm
{
  public:
    BubbleSort(){};
    ~BubbleSort()=default;

    void sort(std::vector<Bar>& array) override;
    
};


#endif // 0#endif
