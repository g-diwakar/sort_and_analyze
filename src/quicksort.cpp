#include"../include/quicksort.hpp"
#include <chrono>
#include <thread>
#include<iostream>
void QuickSort::sort(sf::RenderWindow& w, std::vector<Bar>&array,Appui* ui, float pos_x,bool& start_algorithm)
{
array.push_back(50000);
struct Coordinates
{
    int l;
    int r;
};
class Stack
{
    private:
        Coordinates* coor;
        int T;
    public:
        Stack(int N): T(0) 
        {
            //this is how you caculate floor of lgN
            int t = -1;
            while (N > 0)
            {
                N >>= 1;
                ++t;
            }
            coor = new Coordinates[1+t];
        }
        void push(int ll, int rr)
        {
            ++T;
            coor[T] = {ll, rr};
        }
        Coordinates pop()
        {
            --T;
            return coor[T+1];
        }
        int top()
        {
            return T;
        }
        ~Stack()
        {
            delete[] coor;
        }
};

    const int M = 1;
    int l = 0;
    int r = array.size()-2;
    Stack S(array.size()-1);
    while(1)
    {
      if(!start_algorithm)
      {
        break;
      }
        int i = l;
        int j = r+1;
        int Km = array[l].getValue();
        
        //Km is the key of the pivot to place

        //the inner while loop breaks only when the pivot is placed
        //and array is now ready to be divided into two parts
        while(1)
        {
          if(!start_algorithm)
          {
            break;
          }

            do {++i;            
            array[i].setColor(sf::Color::Red);
            render(w,array,ui,pos_x);
           std::this_thread::sleep_for(std::chrono::milliseconds(50));
            array[i].setDefaultColor();
            render(w,array,ui,pos_x);
          } while(array[i].getValue() < Km);

            do {--j;
                      array[j].setColor(sf::Color::Red);
            render(w,array,ui,pos_x);
           std::this_thread::sleep_for(std::chrono::milliseconds(50));
            array[j].setDefaultColor();
            render(w,array,ui,pos_x);
          } while(array[j].getValue() > Km);


           //array[j].setColor(sf::Color::Red);
            //array[i].setColor(sf::Color::Red);
            //render(w,array,ui,pos_x);
           //std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if (i < j)
            {
             array[j].setDefaultColor();
          array[i].setDefaultColor();
           render(w,array,ui,pos_x);
             //array[j].setDefaultColor();
           //array[i].setDefaultColor();
                Bar temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            else
            {
             array[j].setDefaultColor();
          array[i].setDefaultColor();
           render(w,array,ui,pos_x);
               array[j].setColor(sf::Color::Green);
                render(w,array,ui,pos_x);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
               array[j].setDefaultColor();
                render(w,array,ui,pos_x);
                Bar temp;
                temp = array[l];
                array[l] = array[j];
                array[j] = temp;
                break;
            }
        }
        if (r-j >= j-l && j-l > M) {S.push(j+1,r); r=j-1;}

        //left array > right array; both of them > M, so push left and work on right.
        else if (j-l > r-j && r-j > M) {S.push(l,j-1); l=j+1;}

        //right array is greater than M but left is not; so work on right
        else if (r-j > M && M >= j-l) {l=j+1;}

        //left array is greater than M but right is not; so work on right
        else if (j-l > M && M >= r-j) {r=j-1;}
        else 
        {
            if (S.top() == 0) 
                {
                break;
                } 
            Coordinates temp; 
            temp = S.pop(); 
            l = temp.l; 
            r = temp.r;
        }
    }
    for (int i = 0; i < array.size()-1; ++i)
    {
      if(!start_algorithm)
        break;
          array[i].setColor(sf::Color::Green);
          render(w,array,ui,pos_x);
          std::this_thread::sleep_for(std::chrono::milliseconds(20));
    } 
  start_algorithm=false;
}
