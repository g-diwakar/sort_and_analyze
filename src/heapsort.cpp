#include"../include/heapsort.hpp"

#include<thread>
#include<chrono>
#include<iostream>

void HeapSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool& start_algorithm)
{
  std::cout << array.size() << std::endl;
  for (int i = 0; i < array.size(); ++i)
    {
      std::cout << array[i].getValue() << " ";
    }
  std::cout << std::endl;
    int l = (array.size() >> 1);
    int r = array.size()-1;
    Bar Rm;
    int Km;
    while(1)
    {
    if(!start_algorithm)
        break;
    for (int j = l; j <= r; ++j)
    {
        array[j].setColor(sf::Color(255, 192, 203));
    }
      render(w,array,ui,pos_x);
      std::this_thread::sleep_for(std::chrono::milliseconds(30));

        if (l > 0)
        {
            --l;
            array[l].setColor(sf::Color::Red);
            render(w,array,ui,pos_x);
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            Rm = array[l];
            Km = array[l].getValue();
        }
        else
        {
             Rm = array[r];
             Km = array[r].getValue();
             array[r] = array[0];
             array[r].setColor(sf::Color::Green);
             render(w,array,ui,pos_x);
             array[0] = Rm;
             array[0].setColor(sf::Color::Red);
             render(w,array,ui,pos_x);
             std::this_thread::sleep_for(std::chrono::milliseconds(30));
             --r;

             if (r == 0)
             {
                 array[0] = Rm;
                 break;
             }
        }
        
        int j = l;
        int i;

        while(1)
        {
          if(!start_algorithm)
          { 
            break;
          }
            i = j; 

            if (j == 0)
            {
              j = 1;
            }
            else 
            {
              j = j << 1;
            }

            if (j < r)
            {
                 if (array[j].getValue() < array[j+1].getValue()) {++j;}
            }

            else
            {
                if (j > r) {break;}
            }
            array[i].setColor(sf::Color::Red);
            array[j].setColor(sf::Color::Yellow);
            render(w,array,ui,pos_x);
            std::this_thread::sleep_for(std::chrono::milliseconds(30));


            if (Km >= array[j].getValue()) 
                {break;}  
            else 
                {array[i] = array[j];} 

        }
        array[i] = Rm;
        
    }
  for (int i = 0; i < array.size(); ++i)
    {
      std::cout << array[i].getValue() << " ";

    }
  std::cout << std::endl << array.size() << std::endl;
  start_algorithm=false;

}
