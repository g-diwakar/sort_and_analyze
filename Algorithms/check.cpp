#include <cmath>
#include<iostream>
#include<fstream>
#include <iterator>

struct Cooridnates
{
    int x;
    int y;
  };

int main()
{
  Cooridnates m_coordinates;
  std::ifstream file;
  file.open("bubble.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      std::cout<<m_coordinates.x<<" "<<m_coordinates.y<<std::endl;

    }
  return 0;
}
