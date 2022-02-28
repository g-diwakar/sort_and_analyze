#include "../include/shellsort.hpp"
#include <SFML/System/Sleep.hpp>
#include <chrono>
#include <iostream>
#include <thread>

void ShellSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x, bool& start_algorithm) {

    int H[100] = {0, 1, 5, 19, 41, 109};
    int t = 0;
    do 
    {
        ++t;
    }
    while(H[t] <= array.size() >> 1);

    for (int k = t; k >= 1; --k)
    {
      if(!start_algorithm)
        break;
      int h = H[k-1];
        for (int i = h; i < array.size(); ++i)
        {
          if(!start_algorithm)
            break;
          array[i].setColor(sf::Color::Red);
          render(w,array,ui,pos_x);
          std::this_thread::sleep_for(std::chrono::milliseconds(30));
          int Km = array[i].getValue();
          Bar Rm = array[i];
          int j;
          for (j = i-h; j >= 0; j-=h)
          {  
            if(!start_algorithm)
                break;

            if (array[j].getValue() <= Km)
            {
              break;
            }
            else
            {
              array[j].setColor(sf::Color(111,111,111));
              render(w,array,ui,pos_x);
              std::this_thread::sleep_for(std::chrono::milliseconds(30));  

              array[j+h] = array[j];
              render(w,array,ui,pos_x);
              std::this_thread::sleep_for(std::chrono::milliseconds(30));
              i==j+h? array[i].setColor(sf::Color(111,111,111)) : array[j+h].setDefaultColor();
            }
          }
          array[j+h] = Rm;
          array[i].setDefaultColor();
          array[j+h].setDefaultColor();
          render(w,array,ui,pos_x);
        }
    }
  for(int i=0;i<array.size();i++)
  {if(!start_algorithm)
      break;
    array[i].setColor(sf::Color::Green);
    render(w,array,ui,pos_x);
  }
  start_algorithm=false;
}
