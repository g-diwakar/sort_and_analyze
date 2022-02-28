#include"../include/appui.hpp"
#include"iostream"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Appui::Appui(bool& s_a,bool& r_a,std::vector<bool>& c_a):start_algorithm(s_a),reset_array(r_a),current_algorithm(c_a)
{
  selected_algorithm=0;

  start = new(Button);
  reset = new(Button);
  stop = new(Button);
  b_sort=new(Button);
  h_sort=new(Button);
  i_sort=new(Button);
  q_sort=new(Button);
  se_sort=new(Button);
  sh_sort=new(Button);
  h_separator =new(sf::RectangleShape);
  v_separator = new(sf::RectangleShape);

  start->setPosition(sf::Vector2f(100,780-100));
  reset->setPosition(sf::Vector2f(500,780-100));
  stop->setPosition(sf::Vector2f(800,780-100));
  h_separator->setPosition(sf::Vector2f(0,780-150));
  v_separator->setPosition(sf::Vector2f(1020-145,0));
  b_sort->setPosition(sf::Vector2f(1020-130,10));
  h_sort->setPosition(sf::Vector2f(1020-130,70));
  i_sort->setPosition(sf::Vector2f(1020-130,130));
  q_sort->setPosition(sf::Vector2f(1020-130,190));
  se_sort->setPosition(sf::Vector2f(1020-130,250));
  sh_sort->setPosition(sf::Vector2f(1020-130,310));

  start->setSize(sf::Vector2f(100,50));
  reset->setSize(sf::Vector2f(100,50));
  stop->setSize(sf::Vector2f(100,50));
  h_separator->setSize(sf::Vector2f(1020,5));
  v_separator->setSize(sf::Vector2f(5,780-150));
  b_sort->setSize(sf::Vector2f(100,30));
  h_sort->setSize(sf::Vector2f(100,30));
  i_sort->setSize(sf::Vector2f(100,30));
  q_sort->setSize(sf::Vector2f(100,30));
  se_sort->setSize(sf::Vector2f(100,30));
  sh_sort->setSize(sf::Vector2f(100,30));

  start->setFont("../fonts/lato.ttf");
  reset->setFont("../fonts/lato.ttf");
  stop->setFont("../fonts/lato.ttf");
  b_sort->setFont("../fonts/lato.ttf");
  h_sort->setFont("../fonts/lato.ttf");
  i_sort->setFont("../fonts/lato.ttf");
  q_sort->setFont("../fonts/lato.ttf");
  se_sort->setFont("../fonts/lato.ttf");
  sh_sort->setFont("../fonts/lato.ttf");

  start->setCharacterSize(30);
  reset->setCharacterSize(30);
  stop->setCharacterSize(30);
  b_sort->setCharacterSize(20);
  h_sort->setCharacterSize(20);
  i_sort->setCharacterSize(20);
  q_sort->setCharacterSize(20);
  se_sort->setCharacterSize(20);
  sh_sort->setCharacterSize(20);

  nh_setcolor();
  a_setcolor();
  h_separator->setFillColor(sf::Color(52,73,85));
  v_separator->setFillColor(sf::Color(52,73,85));
  
  start->setString("START");
  reset->setString("RESET");
  stop->setString("STOP");
  b_sort->setString("Bubble");
  h_sort->setString("Heap");
  i_sort->setString("Insertion");
  q_sort->setString("Quick");
  se_sort->setString("Selection");
  sh_sort->setString("Shell");

  b_sort->setBackgroundColor(sf::Color(52,73,85));
  b_sort->setTextColor(sf::Color(249,170,51));
  b_sort->setBorderColor(sf::Color(143,183,143));
}

void Appui::render(sf::RenderWindow &w)
{
 w.draw(*start);
 w.draw(*reset);
 w.draw(*stop);
 w.draw(*h_separator);
 w.draw(*v_separator);
 w.draw(*b_sort);
 w.draw(*i_sort);
 w.draw(*h_sort);
 w.draw(*q_sort);
 w.draw(*se_sort);
 w.draw(*sh_sort);
}

bool Appui::isResetClicked()
{
  return reset->clicked;
}

bool Appui::isStartClicked()
{
  return start->clicked;
}

bool Appui::isStopClicked()
{
  return stop->clicked;
}

bool Appui::isInsertionClicked()
{
  return i_sort->clicked;
}

void Appui::monitor(sf::RenderWindow &w)
{

  start->listen(w);
  reset->listen(w);
  stop->listen(w);
  b_sort->listen(w);
  h_sort->listen(w);
  i_sort->listen(w);
  q_sort->listen(w);
  se_sort->listen(w);
  sh_sort->listen(w);
  
  h_coloredset=false;
  h_setcolor();
  if(!h_coloredset)
    nh_setcolor();
  
  if(start->clicked)
  {
    start_algorithm=true;
  }
  if(stop->clicked)
  {
    start_algorithm=false;
  }

  if(reset->clicked)
  {
    start_algorithm=false;
    reset_array=true;
  }

  if(b_sort->clicked)
  {
   std::cout<<"bubble clicked"<<std::endl;
   selectAlgorithm(0);
   reset_color(selected_algorithm);
   b_sort->setTextColor(sf::Color(237,87,72));
   b_sort->setBorderColor(sf::Color(244,151,142));
   selected_algorithm=0;
  }

  if(h_sort->clicked)
  {
    std::cout<<"heap clicked"<<std::endl;
    selectAlgorithm(1);
    reset_color(selected_algorithm);
    h_sort->setTextColor(sf::Color(237,87,72));
    h_sort->setBorderColor(sf::Color(244,151,142));
    selected_algorithm=1;
  }
  if(i_sort->clicked)
  {
    std::cout<<"insertion clicked"<<std::endl;
    selectAlgorithm(2);
    reset_color(selected_algorithm);
    i_sort->setTextColor(sf::Color(237,87,72));
    i_sort->setBorderColor(sf::Color(244,151,142));
    selected_algorithm=2;
  }
  if(q_sort->clicked)
  {
    std::cout<<"quick clicked"<<std::endl;
    selectAlgorithm(3);
    reset_color(selected_algorithm);
    q_sort->setTextColor(sf::Color(237,87,72));
    q_sort->setBorderColor(sf::Color(244,151,142));
    selected_algorithm=3;
  }
  if(se_sort->clicked)
  {
    std::cout<<"selection clicked"<<std::endl;
    selectAlgorithm(4);
    reset_color(selected_algorithm);
    se_sort->setTextColor(sf::Color(237,87,72));
    se_sort->setBorderColor(sf::Color(244,151,142));
    selected_algorithm=4;
  }
  if(sh_sort->clicked)
  {
    std::cout<<"shell clicked"<<std::endl;
    selectAlgorithm(5);
    reset_color(selected_algorithm);
    sh_sort->setTextColor(sf::Color(237,87,72));
    sh_sort->setBorderColor(sf::Color(244,151,142));
    selected_algorithm=5;
  }
}

void Appui::reset_color(int n)
{
  if(n==0)
  {
     b_sort->setTextColor(sf::Color(249,179,51));
     b_sort->setBorderColor(sf::Color(143,188,143));
  }

  if(n==1)
  {
    h_sort->setTextColor(sf::Color(249,179,51));
    h_sort->setBorderColor(sf::Color(143,188,143));
  }

  if(n==2)
  {
     i_sort->setTextColor(sf::Color(249,179,51));
     i_sort->setBorderColor(sf::Color(143,188,143));
  }
  if(n==3)
  {
     q_sort->setTextColor(sf::Color(249,179,51));
     q_sort->setBorderColor(sf::Color(143,188,143));
  }
  if(n==4)
  {
     se_sort->setTextColor(sf::Color(249,179,51));
     se_sort->setBorderColor(sf::Color(143,188,143));
  }
  if(n==5)
  {
     sh_sort->setTextColor(sf::Color(249,179,51));
     sh_sort->setBorderColor(sf::Color(143,188,143));
  }
}

void Appui::selectAlgorithm(int n)
{
  for(int i=0;i<6;i++)
  {
    current_algorithm[i]=false;
  }
  current_algorithm[n]=true;
  std::cout<<n<<" "<<current_algorithm[n]<<std::endl;
}
void Appui::nh_setcolor()
{
  start->setBackgroundColor(sf::Color(52,73,85));
  reset->setBackgroundColor(sf::Color(52,73,85));
  stop->setBackgroundColor(sf::Color(52,73,85));
 
  start->setTextColor(sf::Color(249,170,51));
  reset->setTextColor(sf::Color(249,170,51));
  stop->setTextColor(sf::Color(249,170,51));
 
  start->setBorderColor(sf::Color(143,188,143));
  reset->setBorderColor(sf::Color(143,188,143));
  stop->setBorderColor(sf::Color(143,188,143));
 }
void Appui::a_setcolor()
{
  b_sort->setBackgroundColor(sf::Color(52,73,85));
  h_sort->setBackgroundColor(sf::Color(52,73,85));
  i_sort->setBackgroundColor(sf::Color(52,73,85));
  q_sort->setBackgroundColor(sf::Color(52,73,85));
  se_sort->setBackgroundColor(sf::Color(52,73,85));
  sh_sort->setBackgroundColor(sf::Color(52,73,85));

  b_sort->setTextColor(sf::Color(237,87,72));
  h_sort->setTextColor(sf::Color(249,179,51));
  i_sort->setTextColor(sf::Color(249,179,51));
  q_sort->setTextColor(sf::Color(249,179,51));
  se_sort->setTextColor(sf::Color(249,179,51));
  sh_sort->setTextColor(sf::Color(249,179,51));

  b_sort->setBorderColor(sf::Color(244,151,142));
  h_sort->setBorderColor(sf::Color(143,188,143));
  i_sort->setBorderColor(sf::Color(143,188,143));
  q_sort->setBorderColor(sf::Color(143,188,143));
  se_sort->setBorderColor(sf::Color(143,188,143));
  sh_sort->setBorderColor(sf::Color(143,188,143));


}

void Appui::h_setcolor()
{
  if(start->hovered)
  {
   start->setBackgroundColor(sf::Color(249,170,51));
   start->setTextColor(sf::Color(52,73,85));
   h_coloredset=true; 
  }
  if(stop->hovered)
  {
    stop->setBackgroundColor(sf::Color(249,170,51));
    stop->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }
  if(reset->hovered)
  {
    reset->setBackgroundColor(sf::Color(249,170,51));
    reset->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }

}

Appui::~Appui(){
   delete start;
  delete reset;
  delete stop;
  delete h_separator;
  delete v_separator;
  delete b_sort;
  delete h_sort;
  delete i_sort;
  delete q_sort;
  delete se_sort;
  delete sh_sort;
}


