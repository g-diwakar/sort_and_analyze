#include"../include/bubblesort.hpp"
#include <chrono>
#include <thread>
#include<iostream>
void BubbleSort::sort(std::vector<Bar>& array)
{
  unsigned i,j;
  for(i=0;i<array.size();i++)
  {
      for(j=0;j<array.size()-i-1;j++)
      {
        array[j].setColor(sf::Color::Red);
        array[j+1].setColor(sf::Color::Red);
 

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        array[j].setDefaultColor();
        array[j+1].setDefaultColor();

        //std::this_thread::sleep_for(std::chrono::milliseconds(13));

        if(isGreater(array[j],array[j+1]))
          swap(array[j],array[j+1]);

        std::cout<<j<<std::endl;     
      }
      array[j].setColor(sf::Color::Green);
    }
}
