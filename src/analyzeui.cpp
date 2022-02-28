#include"../include/analyzeui.hpp"
#include<cmath>
#include<chrono>
#include<thread>
Analyze_ui::Analyze_ui()
{
  graph.setPosition(150,150);
  graph.setSize(sf::Vector2f(1020-300,780-300));   //window_width-300,  window_height-300
  graph.setOutlineThickness(4);
  graph.setOutlineColor(sf::Color(52,73,85));
  graph.setFillColor(sf::Color(0,0,0));
  
  readFiles();

  color_algorithm.push_back(sf::Color::Red);
  color_algorithm.push_back(sf::Color(255,165,0)); //orange
  color_algorithm.push_back(sf::Color(85,107,47)); //dark olive green
  color_algorithm.push_back(sf::Color(143,188,143)); //dark sea green
  color_algorithm.push_back(sf::Color(0,255,255));   //aqua
  color_algorithm.push_back(sf::Color(95,158,160));  //cadet blue
  color_algorithm.push_back(sf::Color(138,43,226));  //blue violet
  color_algorithm.push_back(sf::Color(139,0,139));   //dark magneta
  color_algorithm.push_back(sf::Color(139,69,19));   //shaddle brown
  color_algorithm.push_back(sf::Color(210,105,30));  //chocolate
  color_algorithm.push_back(sf::Color(173,255,47));  //green yellow
  color_algorithm.push_back(sf::Color(153,50,204));  //dark orchid
  
  for(int i=0;i<12;i++)
  {
   active_algorithm.push_back(false);
  }

  active_algorithm[1]=true;
  active_algorithm[7]=true;

}

void Analyze_ui::render(sf::RenderWindow &w)
{ 
  w.draw(graph);
  
  if(active_algorithm[0])
  {
   draw_point(w,0,b_sort); 
  }

   if(active_algorithm[1])
  {
   draw_point(w, 1, d_sort); 
  }
  if(active_algorithm[2])
  {
   draw_point(w,2,h_sort); 
  }
  if(active_algorithm[3])
  {
    draw_point(w,3,iquick_sort);
  }
  if(active_algorithm[4])
  {
    draw_point(w,4,i_sort);
  }
  if(active_algorithm[5])
  {
    draw_point(w,5,i_sort);
  }
  if(active_algorithm[5])
  {
    draw_point(w,5,li_sort);
  }
  if(active_algorithm[6])
  {
    draw_point(w, 6, m_sort);
  }
  if(active_algorithm[7])
  {
    draw_point(w,7,q_sort);
  }
  if(active_algorithm[8])
  {
    draw_point(w,8,r_sort);
  }
  if(active_algorithm[9])
  {
    draw_point(w,9,re_sort);
  }
  if(active_algorithm[10])
  {
    draw_point(w,10,se_sort);
  }
  if(active_algorithm[11])
  {
    draw_point(w,11,sh_sort);
  }
}

void Analyze_ui::draw_point(sf::RenderWindow&w, int n, std::vector<Coordinates>& data)
{
   float x_pos;
   float y_pos;
   for(int i=0;i<data.size();i++)
    {
     // x_pos=get_relative_x((float(data[i].x)/data[data.size()-1].x)*(1020-300));
      //y_pos=get_relative_y((float(data[i].y)/data[data.size()-1].y)*(780-300));
      x_pos=get_relative_x((float(data[i].x)/1000000)*(1020-300));
      y_pos=get_relative_y((float(data[i].y)/1000)*(780-300));
      if(y_pos<150)
         break;

      w.draw(addPixels(x_pos,y_pos,color_algorithm[n]));
      
    }
 
}

void Analyze_ui::monitor(sf::RenderWindow &w)
{

}

sf::RectangleShape Analyze_ui::addPixels(float pos_x,float pos_y,sf::Color color)
{
  sf::RectangleShape pixel;
  pixel.setSize(sf::Vector2f(2,2));
  pixel.setPosition(pos_x,pos_y);
  pixel.setFillColor(color);
  return pixel;
}

float Analyze_ui::get_relative_x(float x)
{
  return(150+x);//graph_position_x+ x
}
float Analyze_ui::get_relative_y(float y)
{
  return((780-150)-y);
}
  
void Analyze_ui::readFiles()
{
  std::ifstream file;
  Coordinates m_coordinates;
  
  file.open("../Algorithms/bubble.txt",std::ios::in);
  while(!file.eof())
  {
    file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
    b_sort.push_back(m_coordinates); 

  }
  file.close();
  
  file.open("../Algorithms/distribution.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      d_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/heap.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      h_sort.push_back(m_coordinates);
    }
  file.close();

  file.open("../Algorithms/improvedquick.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      iquick_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/insertion.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      i_sort.push_back(m_coordinates);
    }
  file.close();

  file.open("../Algorithms/listinsertion.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      li_sort.push_back(m_coordinates);
    }
  file.close();

  file.open("../Algorithms/quick.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      q_sort.push_back(m_coordinates);
    }
  file.close();

  file.open("../Algorithms/radix.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      r_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/radix_exchange.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      re_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/selection.txt",std::ios::in);
  while(!file.eof())
  {
    file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
    se_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/shell.txt",std::ios::in);
  while(!file.eof())
  {
    file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
    sh_sort.push_back(m_coordinates);
  }
  file.close();

  }
