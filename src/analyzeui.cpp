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
  color_algorithm.push_back(sf::Color(0,255,255));   //aqua
  color_algorithm.push_back(sf::Color(138,43,226));  //blue violet
  color_algorithm.push_back(sf::Color(139,0,139));   //dark magneta
  color_algorithm.push_back(sf::Color(139,69,19));   //shaddle brown
  color_algorithm.push_back(sf::Color(210,105,30));  //chocolate
  color_algorithm.push_back(sf::Color(153,50,204));  //dark orchid
  
  for(int i=0;i<9;i++)
  {
   active_algorithm.push_back(false);
  }

  b_bubble=new(Button);
  b_distribution=new(Button);
  b_heap=new(Button);
  b_insertion=new(Button);
  b_merge=new(Button);
  b_quick=new(Button);
  b_radix=new(Button);
  b_selection=new(Button);
  b_shell=new(Button);

  b_bubble->setPosition(sf::Vector2f(150,100));
  b_bubble->setSize(sf::Vector2f(80,30));
  b_bubble->setFont("../fonts/lato.ttf");
  b_bubble->setCharacterSize(20);
  b_bubble->setString("Bubble");
  b_bubble->setBackgroundColor(sf::Color(52,73,85));
  b_bubble->setTextColor(color_algorithm[0]);
  b_bubble->setBorderColor(sf::Color(143,183,143));

  b_selection->setPosition(sf::Vector2f(250,100));
  b_selection->setSize(sf::Vector2f(80,30));
  b_selection->setFont("../fonts/lato.ttf");
  b_selection->setCharacterSize(15);
  b_selection->setString("Selection");
  b_selection->setBackgroundColor(sf::Color(52,73,85));
  b_selection->setTextColor(color_algorithm[7]);
  b_selection->setBorderColor(sf::Color(143,183,143));

  b_insertion->setPosition(sf::Vector2f(350,100));
  b_insertion->setSize(sf::Vector2f(80,30));
  b_insertion->setFont("../fonts/lato.ttf");
  b_insertion->setCharacterSize(15);
  b_insertion->setString("Insertion");
  b_insertion->setBackgroundColor(sf::Color(52,73,85));
  b_insertion->setTextColor(color_algorithm[3]);
  b_insertion->setBorderColor(sf::Color(143,183,143));

  b_distribution->setPosition(sf::Vector2f(1020-140,780-150-30));
  b_distribution->setSize(sf::Vector2f(100,30));
  b_distribution->setFont("../fonts/lato.ttf");
  b_distribution->setCharacterSize(16);
  b_distribution->setString("Distribution");
  b_distribution->setBackgroundColor(sf::Color(52,73,85));
  b_distribution->setTextColor(color_algorithm[1]);
  b_distribution->setBorderColor(sf::Color(143,183,143));

  b_quick->setPosition(sf::Vector2f(1020-140,780-150-80));
  b_quick->setSize(sf::Vector2f(100,30));
  b_quick->setFont("../fonts/lato.ttf");
  b_quick->setCharacterSize(20);
  b_quick->setString("Quick");
  b_quick->setBackgroundColor(sf::Color(52,73,85));
  b_quick->setTextColor(color_algorithm[5]);
  b_quick->setBorderColor(sf::Color(143,183,143));

  b_merge->setPosition(sf::Vector2f(1020-140,780-150-130));
  b_merge->setSize(sf::Vector2f(100,30));
  b_merge->setFont("../fonts/lato.ttf");
  b_merge->setCharacterSize(20);
  b_merge->setString("Merge");
  b_merge->setBackgroundColor(sf::Color(52,73,85));
  b_merge->setTextColor(color_algorithm[4]);
  b_merge->setBorderColor(sf::Color(143,183,143));

  b_radix->setPosition(sf::Vector2f(1020-140,780-150-180));
  b_radix->setSize(sf::Vector2f(100,30));
  b_radix->setFont("../fonts/lato.ttf");
  b_radix->setCharacterSize(20);
  b_radix->setString("Radix");
  b_radix->setBackgroundColor(sf::Color(52,73,85));
  b_radix->setTextColor(color_algorithm[6]);
  b_radix->setBorderColor(sf::Color(143,183,143));

  b_heap->setPosition(sf::Vector2f(1020-140,780-150-230));
  b_heap->setSize(sf::Vector2f(100,30));
  b_heap->setFont("../fonts/lato.ttf");
  b_heap->setCharacterSize(20);
  b_heap->setString("Heap");
  b_heap->setBackgroundColor(sf::Color(52,73,85));
  b_heap->setTextColor(color_algorithm[2]);
  b_heap->setBorderColor(sf::Color(143,183,143));

  b_shell->setPosition(sf::Vector2f(1020-140,780-150-280));
  b_shell->setSize(sf::Vector2f(100,30));
  b_shell->setFont("../fonts/lato.ttf");
  b_shell->setCharacterSize(20);
  b_shell->setString("Shell");
  b_shell->setBackgroundColor(sf::Color(52,73,85));
  b_shell->setTextColor(color_algorithm[8]);
  b_shell->setBorderColor(sf::Color(143,183,143));


  font.loadFromFile("../fonts/lato.ttf");
  x_label.setFont(font);
  y_label.setFont(font);
  max_x.setFont(font);
  max_y.setFont(font);

  x_label.setPosition(1020.00/2-100,780-130);
  x_label.setString("N ---->");
  x_label.setStyle(sf::Text::Bold);
  x_label.setFillColor(sf::Color(173, 141, 52));

  y_label.setPosition(100,780.00/2+100);
  y_label.setString("T ---->");
  y_label.setStyle(sf::Text::Bold);
  y_label.setFillColor(sf::Color(173,141,52));
  y_label.rotate(-90);

  max_x.setPosition(1020-300,30);
  max_x.setCharacterSize(25);
  max_x.setString("N[MAX]: 1000000");
  max_x.setFillColor(sf::Color(173,141,52));
  max_y.setPosition(1020-300,60);
  max_y.setCharacterSize(25);
  max_y.setString("T[MAX]: 1000ms");
  max_y.setFillColor(sf::Color(173,141,52));
} 

void Analyze_ui::render(sf::RenderWindow &w)
{ 
  w.draw(graph);
  w.draw(*b_bubble);
  w.draw(*b_selection);
  w.draw(*b_insertion);
  w.draw(*b_distribution);
  w.draw(*b_quick);
  w.draw(*b_merge);
  w.draw(*b_radix);
  w.draw(*b_heap);
  w.draw(*b_shell);
  w.draw(x_label);
  w.draw(y_label);
  w.draw(max_x);
  w.draw(max_y);
  
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
    draw_point(w,3,i_sort);
  }
  if(active_algorithm[4])
  {
    draw_point(w, 4, m_sort);
  }
  if(active_algorithm[5])
  {
    draw_point(w,5,q_sort);
  }
  if(active_algorithm[6])
  {
    draw_point(w,6,r_sort);
  }
  if(active_algorithm[7])
  {
    draw_point(w,7,se_sort);
  }
  if(active_algorithm[8])
  {
    draw_point(w,8,sh_sort);
  }
}

void Analyze_ui::draw_point(sf::RenderWindow&w, int n, std::vector<Coordinates>& data)
{
   float x_pos;
   float y_pos;
   for(int i=0;i<data.size();i++)
    {
      x_pos=get_relative_x((float(data[i].x)/1000000)*(1020-300));
      y_pos=get_relative_y((float(data[i].y)/1000)*(780-300));
      if(y_pos<150)
         break;

      w.draw(addPixels(x_pos,y_pos,color_algorithm[n]));
      
    }
 
}

void Analyze_ui::monitor(sf::RenderWindow &w)
{
  b_bubble->listen(w);
  b_heap->listen(w);
  b_radix->listen(w);
  b_quick->listen(w);
  b_distribution->listen(w);
  b_selection->listen(w);
  b_insertion->listen(w);
  b_shell->listen(w);
  b_merge->listen(w);
  
  if(b_bubble->clicked)
  {
    take_action(0);
  }
  if(b_distribution->clicked)
  {
    take_action(1);
  }
  if(b_heap->clicked)
  {
    take_action(2);
  }
  if(b_insertion->clicked)
  {
    take_action(3);
  }
  if(b_merge->clicked)
  {
    take_action(4);
  }
  if(b_quick->clicked)
  {
    take_action(5);
  }
  if(b_radix->clicked)
  {
    take_action(6);
  }
  if(b_selection->clicked)
  {
    take_action(7);
  }
  if(b_shell->clicked)
  {
    take_action(8);
  }

}

void Analyze_ui::take_action(int n)
{
  if(active_algorithm[n])
  {
    active_algorithm[n]=false;
  }
  else 
  {
    
    active_algorithm[n]=true;
    
  }
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

  file.open("../Algorithms/merge.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      m_sort.push_back(m_coordinates);
  }
  file.close();

  file.open("../Algorithms/heap.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      h_sort.push_back(m_coordinates);
    }
  file.close();


  file.open("../Algorithms/insertion.txt",std::ios::in);
  while(!file.eof())
  {
      file.read(reinterpret_cast<char*>(&m_coordinates),sizeof(m_coordinates));
      i_sort.push_back(m_coordinates);
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

Analyze_ui::~Analyze_ui()
{
  delete b_bubble;
  delete b_distribution;
  delete b_heap;
  delete b_merge;
  delete b_insertion;
  delete b_quick;
  delete b_radix;
  delete b_selection;
  delete b_shell;
}
