#include "../include/insertionsort.hpp"
#include <SFML/System/Sleep.hpp>
#include <chrono>
#include <iostream>
#include <thread>


void InsertionSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x, bool& start_algorithm) {
  // the first record is already supposed to be sorted so we start from the
  // second
  for (int i = 1; i < array.size(); ++i) {
    if(!start_algorithm)
      break;
    int Km = array[i].getValue();
    Bar temp = array[i];

    array[i].setColor(sf::Color::Red);
    render(w,array,ui,pos_x);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    int j;
    for (j = i - 1; j >= 0; --j) {
      if(!start_algorithm)
      {
        break;
      }
      if (array[j].getValue() <= Km) {
        break;
      } 
      else {
        array[j].setColor(sf::Color(111,111,111));
        render(w,array,ui,pos_x);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));  
        array[j+1]=array[j];
        render(w,array,ui,pos_x);
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        i==(j+1)? array[i].setColor(sf::Color::Red) : array[j+1].setColor(sf::Color::Green);
      }

    }
    array[j + 1] = temp;
    array[i].setColor(sf::Color::Green);
    array[j+1].setColor(sf::Color::Green);
    render(w,array,ui,pos_x);
  }
start_algorithm=false;
  
}
