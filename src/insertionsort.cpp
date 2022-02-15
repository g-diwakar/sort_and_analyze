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

    array[i].setColor(sf::Color::Green);
    render(w,array,ui,pos_x);
    int j;
    for (j = i - 1; j >= 0; --j) {
      if (array[j].getValue() <= Km) {
        break;
      } else {
        array[j].setColor(sf::Color::Green);
        array[j + 1] = array[j];
        render(w,array,ui,pos_x);
      }

    }
    array[j + 1] = temp;
    array[j+1].setColor(sf::Color::Green);
    render(w,array,ui,pos_x);
  }
start_algorithm=false;
  
}
