#include "../include/algorithm.hpp"

void Algorithm::swap(Bar& a, Bar& b)
{
  Bar t;
  t=a;
  a=b;
  b=t;
}

bool Algorithm::isGreater(Bar& a, Bar& b)
{
  return(a>b);
}

bool Algorithm::isLesser(Bar& a, Bar& b)
{
  return (a<b);
}


void Algorithm::render(sf::RenderWindow &w, std::vector<Bar> &array,Appui *ui, float pos_x)
{
  ui->monitor(w);
  w.clear(sf::Color(35,47,52));
  ui->render(w);
 for(int i=0;i<array.size();i++)
  {
    array[i].render(w,pos_x*(i)); 
  }
  w.display();

}
