#include"../include/bubblesort.hpp"
#include <chrono>
#include <thread>
void BubbleSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool& start_algorithm)
{
  unsigned i,j;
  for(i=0;i<array.size();i++)
  {
      if(!start_algorithm)
        break;

      for(j=0;j<array.size()-i-1;j++)
      {
        if(!start_algorithm)
          break;
        array[j].setColor(sf::Color::Red);
        array[j+1].setColor(sf::Color::Red);
 
        render(w,array,ui,pos_x);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        array[j].setDefaultColor();
        array[j+1].setDefaultColor();

        //std::this_thread::sleep_for(std::chrono::milliseconds(13));

        if(isGreater(array[j],array[j+1]))
          swap(array[j],array[j+1]);

      }
      array[j].setColor(sf::Color::Green);
    }
  start_algorithm=false;
}
