#include"../include/heapsort.hpp"

#include<thread>
#include<chrono>
#include<iostream>

void HeapSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool& start_algorithm)
{
  
int l = array.size() >> 1;

    int r = array.size();
    Bar Rm;
    int Km;
    while(1)
    {
    for (int j = l-1; j <= r; ++j)
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
std::this_thread::sleep_for(std::chrono::milliseconds(50));
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
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
            std::this_thread::sleep_for(std::chrono::milliseconds(200));


            if (Km >= array[j].getValue()) 
                {break;}  
            else 
                {array[i] = array[j];} 

        }
        array[i] = Rm;
        
    }
  for(int i=0;i<array.size();i++)
    {
      std::cout<<array[i].getValue()<<" ";
    }
  start_algorithm=false;

}
