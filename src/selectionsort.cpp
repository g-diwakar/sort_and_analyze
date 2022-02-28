#include"../include/selectionsort.hpp"

#include<thread>
#include<chrono>

void SelectionSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool& start_algorithm)
{
  int i,j;
  for(i=0;i<array.size();++i)
  {
      if(!start_algorithm)
        break;
      int smallestId=i;
     for(j=i+1;j<array.size();++j)
      {
        if(!start_algorithm)
        {
          break;
         }
          array[i].setColor(sf::Color::Red);
          array[j].setColor(sf::Color::Yellow);
          render(w, array,  ui,  pos_x);
          std::this_thread::sleep_for(std::chrono::milliseconds(1));
          array[j].setDefaultColor();
         // render(w, array,  ui,  pos_x);

          if(isLesser(array[j],array[smallestId]))
          {
            array[smallestId].setDefaultColor();
            smallestId=j;
            array[smallestId].setColor(sf::Color(255, 192, 203));
            render(w,array,ui,pos_x);
          }

      }
      if(smallestId!=i)
        swap(array[i],array[smallestId]);

      array[smallestId].setDefaultColor();
      array[i].setColor(sf::Color::Green);
      render(w, array,  ui,  pos_x);

  }
  start_algorithm=false;
}
